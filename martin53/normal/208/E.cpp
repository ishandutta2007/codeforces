#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
int depth[nmax];
int in[nmax],out[nmax];
vector<int> order;
int pos=-1;
int parent[nmax];
void dfs(int node,int par)
{
    order.push_back(node);
    parent[node]=par;
    pos++;
    in[node]=pos;

    for(auto k:adj[node])
    {
        depth[k]=depth[node]+1;
        dfs(k,node);
    }

    out[node]=pos;
}

vector<int> tree[4*nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
    tree[node].push_back(depth[order[l]]);
    return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    for(auto k:tree[node*2])
        tree[node].push_back(k);

    for(auto k:tree[node*2+1])
        tree[node].push_back(k);

    sort(tree[node].begin(),tree[node].end());
}

int up[nmax][20];
void precompute()
{
    for(int i=0;i<=n;i++)up[i][0]=parent[i];
    for(int h=1;h<20;h++)
        for(int i=0;i<=n;i++)
        up[i][h]=up[up[i][h-1]][h-1];
    build(1,1,n);
}
int outp[nmax];
int go(int v,int levels)
{
    for(int i=19;i>=0;i--)
        if(levels>=(1<<i))
        {
            v=up[v][i];
            levels=levels-(1<<i);
        }
    return v;
}
int query(int node,int l,int r,int lq,int rq,int value)
{
    if(l==lq&&r==rq)
    {
        int p=lower_bound(tree[node].begin(),tree[node].end(),value)-tree[node].begin();
        int q=upper_bound(tree[node].begin(),tree[node].end(),value)-tree[node].begin();
        return q-p;
    }
    int av=(l+r)/2,ans=0;
    if(lq<=av)ans=ans+query(node*2,l,av,lq,min(av,rq),value);
    if(av<rq)ans=ans+query(node*2+1,av+1,r,max(av+1,lq),rq,value);
    return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n;
int x;
for(int i=1;i<=n;i++)
{
    cin>>x;
    adj[x].push_back(i);
}
    dfs(0,0);
    precompute();

    cin>>m;
    int v,p;
    for(int i=1;i<=m;i++)
    {
        cin>>v>>p;
        if(depth[v]<=p)
        {
        outp[i]=0;
        continue;
        }

        int root=go(v,p);
        outp[i]=query(1,1,n,in[root],out[root],depth[v])-1;
    }

    for(int i=1;i<=m;i++)cout<<outp[i]<<" ";cout<<endl;
return 0;
}