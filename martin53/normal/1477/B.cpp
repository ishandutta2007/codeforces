#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,q;
char inp[nmax],target[nmax];

int l[nmax],r[nmax];

struct info
{
    int sum,lazy;
    int l,r;
};
info tree[nmax*4];

info actual(info a)
{
    if(a.lazy==0)a.sum=0;
    if(a.lazy==1)a.sum=a.r-a.l+1;

    a.lazy=-1;
    return a;
}
info my_merge(info a,info b)
{
    a=actual(a);
    b=actual(b);

    a.sum+=b.sum;
    a.r=b.r;
    return a;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].lazy=target[l]-'0';
        tree[node].sum=target[l]-'0';

        //cout<<"l-> "<<l<<" sum-> "<<tree[node].sum<<endl;

        tree[node].l=l;
        tree[node].r=r;
        return;
    }

    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

void push(int node)
{
    if(tree[node].lazy==-1)return;

    tree[node*2].lazy=tree[node].lazy;
    tree[node*2+1].lazy=tree[node].lazy;
    tree[node].lazy=-1;
}

int ask(int node,int l,int r,int lq,int rq)//returns count of ones
{
    if(tree[node].lazy==0)return 0;
    else if(tree[node].lazy==1)return rq-lq+1;

    push(node);

    int av=(l+r)/2;

    int ret=0;

    if(lq<=av)ret=ret+ask(node*2,l,av,lq,min(av,rq));
    if(av<rq)ret=ret+ask(node*2+1,av+1,r,max(av+1,lq),rq);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    return ret;
}

void update(int node,int l,int r,int lq,int rq,int val)
{
    if(lq==l&&rq==r)
    {
        tree[node].lazy=val;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void solve()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
    }

    //cout<<"--"<<endl;

    for(int i=1;i<=n;i++)
    {
        cin>>target[i];
    }

    //cout<<"----"<<endl;

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&l[i],&r[i]);
    }

    for(int i=1;i<=4*n;i++)
    {
        tree[i].sum=0;
        tree[i].lazy=-1;
    }

    build(1,1,n);

    /*
    for(int i=1;i<=n;i++)
        cout<<ask(1,1,n,i,i)<<" ";cout<<endl;
    */

    for(int i=q;i>=1;i--)
    {
        int one=ask(1,1,n,l[i],r[i]);
        int zero=r[i]-l[i]+1-one;

        //cout<<"i= "<<i<<" one= "<<one<<" zero= "<<zero<<endl;

        if(one==zero)
        {
            printf("NO\n");
            return;
        }

        if(one>zero)
        {
            update(1,1,n,l[i],r[i],1);
        }
        else
        {
            update(1,1,n,l[i],r[i],0);
        }
    }

    for(int i=1;i<=n;i++)
    {
        int me=ask(1,1,n,i,i);

        if(me==1&&inp[i]=='0')
        {
            printf("NO\n");
            return;
        }

        if(me==0&&inp[i]=='1')
        {
            printf("NO\n");
            return;
        }

    }

    printf("YES\n");

    //cout<<"---"<<endl;
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        solve();
    }

    return 0;
}