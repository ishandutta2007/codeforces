#include<bits/stdc++.h>
using namespace std;
const int nmax=150042;
int n,q,p,arr[nmax];
struct info
{
    int l,r;
    int lazy;
    pair<int/*number*/,int/*occurrences*/> seen[10];
    int sz;
};
info tree[4*nmax];
int keep;

bool cmp(pair<int/*number*/,int/*occurrences*/> a,pair<int/*number*/,int/*occurrences*/> b)
{
    return a.second>b.second;
}
info my_merge(info a,info b)
{
    info ret;
    ret.l=a.l;
    ret.r=b.r;
    ret.lazy=0;

    ret.sz=a.sz;
    for(int i=0;i<a.sz;i++)
        ret.seen[i]=a.seen[i];

    for(int j=0;j<b.sz;j++)
    {
        bool ok=0;
        for(int i=0;i<ret.sz;i++)
            if(ret.seen[i].first==b.seen[j].first)
            {
                ret.seen[i].second+=b.seen[j].second;
                ok=1;
                break;
            }
        if(ok==0)
        {
            ret.seen[ret.sz]=b.seen[j];
            ret.sz++;
        }
    }
    sort(ret.seen,ret.seen+ret.sz,cmp);
    while(ret.sz&&(ret.sz>keep||ret.seen[ret.sz-1].second<=0))
    {
        int rem=ret.seen[ret.sz-1].second;
        ret.sz--;
        for(int j=0;j<ret.sz;j++)
            ret.seen[j].second=max(0,ret.seen[j].second-rem);
    }
    return ret;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].l=l;
        tree[node].r=r;
        tree[node].lazy=0;
        tree[node].sz=1;
        tree[node].seen[0]={arr[l],1};
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

void note(int node,int l,int r,int value)
{
    tree[node].lazy=value;
    tree[node].seen[0]={value,r-l+1};
    tree[node].sz=1;
}
void update(int node,int l,int r,int lq,int rq,int value)
{
    if(l==lq&&r==rq)
    {
        note(node,l,r,value);
        return;
    }
    int av=(l+r)/2;

    if(tree[node].lazy)note(node*2,l,av,tree[node].lazy);
    if(tree[node].lazy)note(node*2+1,av+1,r,tree[node].lazy);
    tree[node].lazy=0;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),value);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,value);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];

    int av=(l+r)/2;

    if(tree[node].lazy)note(node*2,l,av,tree[node].lazy);
    if(tree[node].lazy)note(node*2+1,av+1,r,tree[node].lazy);
    tree[node].lazy=0;

    info ret;
    if(lq<=av&&av+1<=rq)ret=my_merge(query(node*2,l,av,lq,av),query(node*2+1,av+1,r,av+1,rq));
    else if(lq<=av)ret=query(node*2,l,av,lq,rq);
    else ret=query(node*2+1,av+1,r,lq,rq);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    return ret;
}
int main()
{
    scanf("%i%i%i",&n,&q,&p);
    for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

    keep=100/p;

    build(1,1,n);

    int type,l,r,value;
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&type,&l,&r);
        if(type==1)
        {
            scanf("%i",&value);
            update(1,1,n,l,r,value);
        }
        else
        {
            info output=query(1,1,n,l,r);
            printf("%i",output.sz);
            for(int k=0;k<output.sz;k++)
                printf(" %i",output.seen[k].first);
            printf("\n");
        }
    }
    return 0;
}