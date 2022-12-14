#include<bits/stdc++.h>
using namespace std;
int n,a[222222],tp,l,r,k,q,crt;
struct treenode
{
    int sum,len,mn1,mn2,lazy;
    bool can(int a,int b)
    {
        if (mn1<=0 || mn2<0) return 0;
        if ((b-a)&1) return (sum==0);
        return (sum==1);
    }
}tree1[888888],tree2[888888],t1,t2;
void merge(treenode &a,treenode b,treenode c)
{
    a.lazy=0;a.len=b.len+c.len;
    if (b.len&1)
    {
        a.sum=b.sum-c.sum;
    }
    else
    {
        a.sum=b.sum+c.sum;
    }
    if (c.len&1)
    {
        a.mn1=min(c.mn1,b.mn2+c.sum);
        a.mn2=min(c.mn2,b.mn1-c.sum);
    }
    else
    {
        a.mn1=min(c.mn1,b.mn1-c.sum);
        a.mn2=min(c.mn2,b.mn2+c.sum);
    }
}
void build1(int l,int r,int node)
{
    tree1[node].len=r-l+1;
    if (l==r)
    {
        tree1[node].sum=tree1[node].mn1=a[l];
        tree1[node].lazy=0;
        tree1[node].mn2=1e9;
        return;
    }
    int mid=(l+r)>>1;
    build1(l,mid,node<<1);
    build1(mid+1,r,(node<<1)|1);
    merge(tree1[node],tree1[node<<1],tree1[(node<<1)|1]);
}
void build2(int l,int r,int node)
{
    tree2[node].len=r-l+1;
    if (l==r)
    {
        tree2[node].sum=tree2[node].mn1=a[n-l+1];
        tree2[node].lazy=0;
        tree2[node].mn2=1e9;
        return;
    }
    int mid=(l+r)>>1;
    build2(l,mid,node<<1);
    build2(mid+1,r,(node<<1)|1);
    merge(tree2[node],tree2[node<<1],tree2[(node<<1)|1]);
}
void push1(int node,int x)
{
    if (tree1[node].len&1) tree1[node].sum+=x;
    tree1[node].mn1+=x;
    tree1[node].lazy+=x;
}
void pushdown1(int node)
{
    if (tree1[node].lazy)
    {
        push1(node<<1,tree1[node].lazy);
        push1((node<<1)|1,tree1[node].lazy);
        tree1[node].lazy=0;
    }
}
void update1(int beg,int en,int l,int r,int node,int x)
{
    if (l>en || r<beg) return;
    if (l>=beg && r<=en) 
    {
        push1(node,x);
        return;
    }
    int mid=(l+r)>>1;
    pushdown1(node);
    update1(beg,en,l,mid,node<<1,x);
    update1(beg,en,mid+1,r,(node<<1)|1,x);
    merge(tree1[node],tree1[node<<1],tree1[(node<<1)|1]);
}
treenode query1(int beg,int en,int l,int r,int node)
{
    if (l>=beg && r<=en) return tree1[node];
    int mid=(l+r)>>1;
    pushdown1(node);
    if (en<=mid) return query1(beg,en,l,mid,node<<1);
    if (beg>mid) return query1(beg,en,mid+1,r,(node<<1)|1);
    treenode res;
    merge(res,query1(beg,en,l,mid,node<<1),query1(beg,en,mid+1,r,(node<<1)|1));
    return res;
}
void push2(int node,int x)
{
    if (tree2[node].len&1) tree2[node].sum+=x;
    tree2[node].mn1+=x;
    tree2[node].lazy+=x;
}
void pushdown2(int node)
{
    if (tree2[node].lazy)
    {
        push2(node<<1,tree2[node].lazy);
        push2((node<<1)|1,tree2[node].lazy);
        tree2[node].lazy=0;
    }
}
void update2(int beg,int en,int l,int r,int node,int x)
{
    if (l>en || r<beg) return;
    if (l>=beg && r<=en) 
    {
        push2(node,x);
        return;
    }
    int mid=(l+r)>>1;
    pushdown2(node);
    update2(beg,en,l,mid,node<<1,x);
    update2(beg,en,mid+1,r,(node<<1)|1,x);
    merge(tree2[node],tree2[node<<1],tree2[(node<<1)|1]);
}
treenode query2(int beg,int en,int l,int r,int node)
{
    if (l>=beg && r<=en) return tree2[node];
    int mid=(l+r)>>1;
    pushdown2(node);
    if (en<=mid) return query2(beg,en,l,mid,node<<1);
    if (beg>mid) return query2(beg,en,mid+1,r,(node<<1)|1);
    treenode res;
    merge(res,query2(beg,en,l,mid,node<<1),query2(beg,en,mid+1,r,(node<<1)|1));
    return res;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build1(1,n,1);build2(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&tp);
        if (tp==1)
        {
            scanf("%d%d%d",&l,&r,&k);
            l++;r++;
            update1(l,r,1,n,1,k);
            update2(n+1-r,n+1-l,1,n,1,k);
        }
        else
        {
            scanf("%d%d",&l,&r);l++;r++;
            t1=query1(l,r,1,n,1);t2=query2(n+1-r,n+1-l,1,n,1);
            if (t1.can(l,r) || t2.can(l,r)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}