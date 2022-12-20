#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,q;
long long arr[nmax];
struct quer
{
    int l,r,id;
};
vector< quer > inp[nmax];
long long output[nmax];

vector< pair<int/*to*/,int/*cost*/> > adj[nmax];
int t;
int in[nmax],out[nmax];
long long dist[nmax];
void dfs(int node,int parent,long long d)
{
    //cout<<node<<" -> "<<d<<endl;
    if(node==1||adj[node].size()>=2)dist[node]=1e18;
    else dist[node]=d;

    t++;
    in[node]=t;

    for(auto k:adj[node])
        if(k.first!=parent)dfs(k.first,node,d+k.second);

    out[node]=t;
}
struct info
{
    long long lazy,mini;
};
info tree[nmax*4];
info actual(info now)
{
    now.mini=now.mini+now.lazy;
    now.lazy=0;
    return now;
}
info my_merge(info a,info b)
{
    a=actual(a);
    b=actual(b);

    if(a.mini<b.mini)return a;
    return b;
}
void push(int node)
{
    tree[node*2].lazy+=tree[node].lazy;
    tree[node*2+1].lazy+=tree[node].lazy;

    tree[node].lazy=0;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].mini=dist[l];
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void update(int node,int l,int r,int lq,int rq,int value)
{
    if(l==lq&&r==rq)
    {
        tree[node].lazy+=value;
        return;
    }
    push(node);
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(av,rq),value);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,value);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return actual(tree[node]);
    push(node);
    int av=(l+r)/2;

    info ret;ret.lazy=0;ret.mini=1e18;

    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    return ret;
}
void go_into(int node,int add)
{
    int p=in[node],q=out[node];

    update(1,1,n,p,q,add);
    if(p!=1)update(1,1,n,1,p-1,-add);
    if(q!=n)update(1,1,n,q+1,n,-add);
}

void solve(int node,int parent)
{
    for(auto k:inp[node])
        output[k.id]=actual(query(1,1,n,k.l,k.r)).mini;

    for(auto k:adj[node])
        if(k.first!=parent)
        {
            go_into(k.first,-k.second);
            solve(k.first,node);
            go_into(k.first,k.second);
        }
}
int main()
{
scanf("%i%i",&n,&q);

int p,w;
for(int i=2;i<=n;i++)
{
    scanf("%i%i",&p,&w);
    adj[i].push_back({p,w});
    adj[p].push_back({i,w});
}

dfs(1,0,0);

build(1,1,n);

quer now;
int v;
for(int i=1;i<=q;i++)
{
    scanf("%i%i%i",&v,&now.l,&now.r);
    now.id=i;
    inp[v].push_back(now);
}

solve(1,0);

for(int i=1;i<=q;i++)
    printf("%lld\n",output[i]);
return 0;
}