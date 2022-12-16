#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n;
long long inp[nmax];

long long output[nmax];

long long tree[4*nmax];

void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node]=val;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,val);
    else update(node*2+1,av+1,r,pos,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int node,int l,int r,long long val)
{
    if(l==r)return l;
    int av=(l+r)/2;

    if(tree[node*2]==0)return query(node*2+1,av+1,r,val);

    if(tree[node*2]>val)return query(node*2,l,av,val);
    return query(node*2+1,av+1,r,val-tree[node*2]);
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&inp[i]);
        update(1,1,n,i,i);
    }

    for(int i=n;i>=1;i--)
    {
        output[i]=query(1,1,n,inp[i]);
        update(1,1,n,output[i],0);
    }

    for(int i=1;i<=n;i++)
        printf("%lld ",output[i]);
}