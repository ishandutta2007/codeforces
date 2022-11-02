#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;
using pii = pair<int,int>;
 
void dfs(int node, int p, int par[], vi G[])
{
    par[node] = p;
 
    for(auto it: G[node])
    {
        if(it == p)
            continue;
        if(par[it] == -1)
        {
            par[it] = node;
            dfs(it,node,par,G);
        }
    }
}
 
pii ss(int node, int par[], vi G[])
{
    if(G[node].size() == 1 && par[node]!=node)
        return {1,1};
 
    pii can = {0,1e9};
    vector<int> backtrack;
    for(auto it: G[node])
    {
        if(it == par[node])
            continue;
 
        pii gg = ss(it,par,G);
        can.first = max(can.first,gg.first);
        backtrack.push_back(gg.second);
        can.second = min(can.second,gg.second);
    }
 
    sort(backtrack.begin(),backtrack.end());
 
    if(node == par[node])
    {
        can.first = max(can.first,backtrack.back());
        backtrack.pop_back();
        if(!backtrack.empty())
            can.first = max(can.first,backtrack.back()+1);
    }
 
    if(node != par[node])
    {
        //phase 2 goes here
        can.first = max(can.first,backtrack.back()+1);
        can.second++;
    }
    //cout<<node<<' '<<can.first<<' '<<can.second<<endl;
    return can;
}
 
int solve()
{
    int n,i,j;
    cin>>n;
    int par[n];
    vi G[n];
    for(i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(i=0; i<n; i++)
        par[i] = -1;
    dfs(0,0,par,G);
    cout<<ss(0,par,G).first<<endl;
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}