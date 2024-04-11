#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42,MX=(1<<20)+42;

int n,inp[nmax];

pair<int,int> tree[20][MX];

pair<int,int> my_merge(pair<int,int> le,pair<int,int> ri)
{
    return {min(le.first,ri.first),max(le.second,ri.second)};
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[0][node]={max(1,l-inp[l]),min(3*n,l+inp[l])};
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[0][node]=my_merge(tree[0][node*2],tree[0][node*2+1]);
}

pair<int,int> query(int id,int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[id][node];

    pair<int,int> ret={1e9,0};
    int av=(l+r)/2;

    if(lq<=av)ret=my_merge(ret,query(id,node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(id,node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}

void build_other(int id,int node,int l,int r)
{
    if(l==r)
    {
        tree[id][node]=query(id-1,1,1,3*n,tree[id-1][node].first,tree[id-1][node].second);

        //cout<<id<<" "<<l<<" "<<r<<" -> "<<tree[id][node].first<<" "<<tree[id][node].second<<endl;

        return;
    }

    int av=(l+r)/2;
    build_other(id,node*2,l,av);
    build_other(id,node*2+1,av+1,r);

    tree[id][node]=my_merge(tree[id][node*2],tree[id][node*2+1]);
}

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(n==1)
    {
        printf("0\n");
        return 0;
    }

    for(int i=n+1;i<=3*n;i++)
        inp[i]=inp[i-n];

    build(1,1,3*n);
    for(int sz=1;sz<20;sz++)
    {
        build_other(sz,1,1,3*n);
    }

    for(int i=1;i<=n;i++)
    {
        int outp=0;

        pair<int,int> active={i+n,i+n};

        for(int sz=19;sz>=0;sz--)
        {
            pair<int,int> cur=query(sz,1,1,3*n,active.first,active.second);

            if(cur.second-cur.first+1<n)
            {
                outp+=(1<<sz);
                active=cur;
            }
        }

        printf("%i ",outp+1);
    }

    return 0;
}