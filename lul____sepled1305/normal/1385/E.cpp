#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int T,counti;
bool pass;
using pii = pair<int,int>;

void dfs(vector<int> G[],int node,int topo[], bool visit[])
{
    if(visit[node] && topo[node] == -1)
        pass = false;
    else if(visit[node])
    {
        ;
    }
    else if(G[node].size()==0)
    {
        visit[node] = true;
        topo[node] = counti;
        counti++;
    }
    else
    {
        visit[node] = true;
        for(auto it: G[node])
            dfs(G,it,topo,visit);
        topo[node] = counti;
        counti++;
    }
}

void solve()
{
    counti = 0;
    pass = true;
    int n,m,i;
    cin>>n>>m;
    vector<pii> undirect;
    vector<int> left_over,G[n];
    int topo[n];
    bool start[n];
    bool visit[n];
    for(i=0;i<n;i++)
        start[i] = true, topo[i] = -1, visit[i] = false;
    for(i=0;i<m;i++)
    {
        int t,a,b;
        cin>>t>>a>>b;
        a--,b--;
        if(t==0)
            undirect.pb({a,b});
        else
            G[a].pb(b),start[b] = false;
    }
    for(i=0;i<n;i++)
    {
        if(start[i] && G[i].size()>0)
            dfs(G,i,topo,visit);
        else if(start[i] && G[i].size()==0)
            left_over.pb(i);
    }
    for(auto it: left_over)
    {
        visit[it] = true;
        topo[it] = counti;
        counti++;
    }
    for(auto it: undirect)
    {
        int a = it.first, b = it.second;
        if(topo[a] > topo[b])
            G[a].push_back(b);
        else
            G[b].push_back(a);
    }
    for(i=0;i<n;i++)
    {
        if(!visit[i])
            pass = false;
    }
    if(!pass)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(i=0;i<n;i++)
        {
            for(auto it: G[i])
                cout<<i+1<<" "<<it+1<<"\n";
        }
    }
}

int main()
{
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}