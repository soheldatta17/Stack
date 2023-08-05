#include<stdio.h>
#include<stdlib.h>
int top=-1,s,e,p;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*temp,*head;
int isFull()
{
    if(top==s-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}
void push(struct Node *n)
{
    top=top+1;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=e;
    if(top==0)
    {
        head=n;
        n->next=NULL;
        n->prev=NULL;
        temp=n;
    }
    else
    {
        temp->next=n;
        n->prev=temp;
        n->next=NULL;
        temp=n;
    }
}
int pop(struct Node *n)
{
    p=temp->data;
    if(top>0)
    {
        temp->prev->next=NULL;
    }
    top=top-1;
    return p;
}
void print()
{
    printf("\nPrinting the stack: ");
    struct Node *pr;
    pr=head;
    while(pr!=NULL)
    {
        printf("%d ",pr->data);
        pr=pr->next;
    }
}
void main()
{
    int a;
    printf("\nEnter the size of the stack:");
    scanf("%d",&s);
    struct Node *n;
    while(1)
    {
        printf("\nEnter 1 to push 2 to pop and 3 to display: ");
        scanf("%d",&a);
    
    switch(a)
    {
        case 1:
        if(isFull()==0)
        {
            printf("\nEnter the no. ");
            scanf("%d",&e);
            push(n);
        }
        else
        {
            printf("\nStack is full\n");
        }
        break;
        case 2:
        if(isEmpty()==0)
        {
            printf("\nThe element popped is %d\n",pop(n));
        }
        else
        {
            printf("\nStack is empty\n");
        }
        break;
        case 3:
        print();
        break;
        default:
        printf("\nInvalid choice\n");
    }
    }
}