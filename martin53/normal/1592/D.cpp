#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int ask(set<int> cur)
{
    cout<<"? "<<cur.size();for(auto w:cur)cout<<" "<<w;cout<<endl;

    int ret;
    cin>>ret;

    return ret;
}

int n;
vector<int> adj[nmax];

int MX;

vector< pair<int,int> > edges;

void dfs(int node,int parent)
{
    for(auto w:adj[node])
        if(w!=parent)
        {
            edges.push_back({w,node});

            dfs(w,node);

            edges.push_back({node,w});
        }
}

int main()
{
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> all={};
    for(int i=1;i<=n;i++)all.insert(i);

    MX=ask(all);

    dfs(1,0);

    int ok=0,not_ok=edges.size();

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        set<int> given={};

        for(int j=ok;j<av;j++)
        {
            given.insert(edges[j].first);
            given.insert(edges[j].second);
        }

        if(ask(given)!=MX)ok=av;
        else not_ok=av;
    }

    cout<<"! "<<edges[ok].first<<" "<<edges[ok].second<<endl;

    return 0;
}