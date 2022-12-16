#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax],output[nmax];
int tree[4*nmax];

void push(int node)
{
    tree[node*2]=max(tree[node*2],tree[node]);
    tree[node*2+1]=max(tree[node*2+1],tree[node]);
    tree[node]=0;
}
void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node]=val;
        return;
    }
    push(node);
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,val);
    else update(node*2+1,av+1,r,pos,val);
}

void solve(int node,int l,int r)
{
    if(l==r)
    {
        output[l]=tree[node];
        return;
    }
    push(node);
    int av=(l+r)/2;
    solve(node*2,l,av);
    solve(node*2+1,av+1,r);
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=inp[l];
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int q;
    scanf("%i",&q);

    build(1,1,n);

    int type=0,val,pos;
    for(int i=1;i<=q;i++)
    {
        scanf("%i",&type);
        if(type==2)
        {
            scanf("%i",&val);
            tree[1]=max(tree[1],val);
        }
        else
        {
            scanf("%i%i",&pos,&val);
            update(1,1,n,pos,val);
        }
    }

    solve(1,1,n);

    for(int i=1;i<=n;i++)printf("%i ",output[i]);
    return 0;
}