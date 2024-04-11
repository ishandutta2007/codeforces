#include <bits/stdc++.h>
 
using namespace std;
#define mp make_pair
 
vector<vector<int>> ops;
vector<vector<pair<int, int>>> G;
vector<vector<int>> leaves;
vector<bool> visited;
vector<int> pr;
int root = 1;
 
void dfs1(int s)
{
    visited[s] = true;
    for (auto it: G[s]) if (!visited[it.first]) {pr[it.first] = s; dfs1(it.first); leaves[s].push_back(leaves[it.first][0]);}
    if (leaves[s].size()==0) leaves[s].push_back(s);
}
 
void add_path(int v, int x)
{
    if (leaves[v].size()==1) {ops.push_back({root, v, x}); return;}
    ops.push_back({root, leaves[v][0], x/2});
    ops.push_back({root, leaves[v][1], x/2});
    ops.push_back({leaves[v][0], leaves[v][1], -x/2});
}
 
void add_edge(int v, int x)
{
    if (pr[v]==root) {add_path(v, x); return;}
    add_path(v, x);
    add_path(pr[v], -x);
}
 
void dfs2(int s)
{
    visited[s] = true;
    for (auto it: G[s]) if (!visited[it.first]) {add_edge(it.first, it.second); dfs2(it.first);}
}
 
int main()
{
    int n;
    cin>>n;
    G.resize(n+1);
    leaves.resize(n+1);
    visited.resize(n+1);
    pr.resize(n+1);
    int u, v, val;
    for (int i = 0; i<n-1; i++)
    {
        cin>>u>>v>>val;
        G[u].push_back(mp(v, val));
        G[v].push_back(mp(u, val));
    }
 
    vector<pair<int, int>> test1 = {mp(2, 6), mp(3, 8), mp(4, 12)};
    vector<pair<int, int>> test2 = {mp(1, 6), mp(5, 2), mp(6, 4)};    
   
    for (int i = 1; i<=n; i++) if (G[i].size()==2) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    while (G[root].size()!=1) root++;
    dfs1(root);
    visited = vector<bool>(n+1);
    dfs2(root);
    cout<<ops.size()<<endl;
    for (auto it: ops) cout<<it[0]<<' '<<it[1]<<' '<<it[2]<<endl;
}