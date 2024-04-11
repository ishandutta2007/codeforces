#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,inf=1e9+42;
vector<int> adj[nmax];
int n,r,arr[nmax];
vector< pair<int/*distance*/,int/*value*/> > tree[nmax*4],now;
pair<int,int> cover[nmax];
int height[nmax],order[nmax];
int in=0;
void dfs(int node,int parent,int h)
{
    height[node]=h;
    in++;
    cover[node].first=in;
    order[in]=node;
    for(auto k:adj[node])
        if(parent!=k)
        dfs(k,node,h+1);
    cover[node].second=in;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].push_back({height[order[l]],arr[order[l]]});
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=tree[node*2];
    for(auto k:tree[node*2+1])
        tree[node].push_back(k);
    sort(tree[node].begin(),tree[node].end());
    now={};
    now.push_back(tree[node][0]);
    int SZ=tree[node].size(),sz_now=0;
    for(int i=1;i<SZ;i++)
        if(now[sz_now].first!=tree[node][i].first)
        {
            now.push_back(tree[node][i]);
            sz_now++;
        }
    tree[node]=now;
    SZ=tree[node].size();
    for(int i=1;i<SZ;i++)
        tree[node][i].second=min(tree[node][i-1].second,tree[node][i].second);
}
int query(int node,int l,int r,int lq,int rq,int mx)
{
    if(l==lq&&r==rq)
    {
        int ok=-1,not_ok=tree[node].size(),av;
        while(not_ok-ok>1)
        {
            av=(ok+not_ok)/2;
            if(tree[node][av].first<=mx)ok=av;
            else not_ok=av;
        }
        if(ok==-1)return inf;
        return tree[node][ok].second;
    }
    int av=(l+r)/2,ret=inf;
    if(lq<=av)ret=min(ret,query(node*2,l,av,lq,min(av,rq),mx));
    if(av<rq)ret=min(ret,query(node*2+1,av+1,r,max(lq,av+1),rq,mx));
    return ret;
}
int main()
{
scanf("%i%i",&n,&r);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
int x,y;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}

dfs(r,0,0);

build(1,1,n);

int m;
int last=0;
int p,q,k;
scanf("%i",&m);
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&p,&q);
    x=((p+last)%n)+1;
    k=(q+last)%n;
    last=query(1,1,n,cover[x].first,cover[x].second,k+height[x]);
    printf("%i\n",last);
}
return 0;
}