#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,p;

pair<int,int> inp[nmax];

int tree[nmax*4];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=inp[l].first;
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=__gcd(tree[node*2],tree[node*2+1]);
}

int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];

    int av=(l+r)/2;
    int ret=0;

    if(lq<=av)ret=__gcd(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=__gcd(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}

set<int> components;
int parent[nmax];

int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

int l[nmax],r[nmax];

void my_merge(int u,int v)
{
    u=root(u);
    v=root(v);

    if(u>v)swap(u,v);

    parent[v]=u;
    r[u]=r[v];
}

long long outp=0;

void merge_around(int which,int g)
{
    bool go=1;

    while(go)
    {
        int node=root(which);

        //cout<<"gaz "<<which<<" "<<node<<" "<<l[node]<<" "<<r[node]<<endl;

        go=0;

        if(l[node]!=1&&query(1,1,n,l[node]-1,which)==g)
        {
            outp+=g;

            my_merge(node,l[node]-1);
            go=1;
        }
        else if(r[node]!=n&&query(1,1,n,which,r[node]+1)==g)
        {
            outp+=g;

            my_merge(node,r[node]+1);
            go=1;
        }

    }

    //cout<<"stop "<<which<<endl;
}
long long solve()
{
    outp=0;

    scanf("%i%i",&n,&p);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i].first);

    for(int i=1;i<=n;i++)parent[i]=i;

    build(1,1,n);

    for(int i=1;i<=n;i++)l[i]=i,r[i]=i;

    for(int i=1;i<=n;i++)inp[i].second=i;

    sort(inp+1,inp+n+1);

    for(int i=1;i<=n&&inp[i].first<p;i++)
        merge_around(inp[i].second,inp[i].first);

    set<int> active={};
    for(int i=1;i<=n;i++)
        active.insert(root(i));

    outp+=1LL*p*(active.size()-1);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}