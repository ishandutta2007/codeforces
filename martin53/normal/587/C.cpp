#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=11,ST=20;
int n,m,q;
vector<int> adj[nmax];
vector<int> people[nmax];
int parent[nmax];

int go_up[nmax][ST];
int depth[nmax];
void dfs(int node,int par)
{
parent[node]=par;
for(auto k:adj[node])
    if(k!=par)
    {
    depth[k]=depth[node]+1;
    dfs(k,node);
    }
}
vector<int> ans[nmax][ST];//node and (2^i)-1 up

vector<int> my_merge(vector<int> a,vector<int> b)
{
for(auto k:b)a.push_back(k);
sort(a.begin(),a.end());
while(a.size()>=LIM)a.pop_back();
return a;
}
void precalc()
{
    for(int i=1;i<=n;i++)
    {
    go_up[i][0]=parent[i];
    ans[i][0]=people[i];
    }
    for(int h=1;h<ST;h++)
        for(int i=1;i<=n;i++)
        {
        go_up[i][h]=go_up[go_up[i][h-1]][h-1];
        ans[i][h]=my_merge(ans[i][h-1],ans[go_up[i][h-1]][h-1]);
        }
}

vector<int> find_ans(int node,int height)
{
vector<int> result={};
for(int i=ST-1;i>=0;i--)
    if((height&(1<<i)))
    {
    result=my_merge(result,ans[node][i]);
    height=height-(1<<i);
    node=go_up[node][i];
    }
return result;
}
int find_lca(int u,int v)
{
if(depth[u]<depth[v])swap(u,v);
for(int i=ST-1;i>=0;i--)
    if(depth[u]-(1<<i)>=depth[v])u=go_up[u][i];
if(u==v)return u;
for(int i=ST-1;i>=0;i--)
    if(go_up[u][i]!=go_up[v][i])
    {
    u=go_up[u][i];
    v=go_up[v][i];
    }
return parent[u];
}
vector<int> query(int u,int v)
{
int lca=find_lca(u,v);
vector<int> p=people[lca];
vector<int> q=my_merge(find_ans(u,depth[u]-depth[lca]),find_ans(v,depth[v]-depth[lca]));
return my_merge(p,q);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m>>q;
int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
int c;
for(int i=1;i<=m;i++)
{
cin>>c;
people[c].push_back(i);
}
for(int i=1;i<=n;i++)
{
sort(people[i].begin(),people[i].end());
int sz=people[i].size();
    while(sz>=LIM)
    {
    people[i].pop_back();
    sz--;
    }
}

dfs(1,1);
precalc();

int u,v,a;
for(int i=1;i<=q;i++)
{
cin>>u>>v>>a;
vector<int> ans=query(u,v);
while(ans.size()>a)ans.pop_back();
/*cout<<"outp: ";*/
cout<<ans.size();for(auto k:ans)cout<<" "<<k;cout<<endl;
}

return 0;
}