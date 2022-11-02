#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 5e3+10;
int topo[N];
int counti,n,m,i,a,b;
vector<int> G[N];
bool visit[N];
bool tree = true;
vector<pii> edge;

void dfs(int node)
{
    visit[node] = true;
    for(auto it: G[node])
    {
        if(visit[it] && topo[it]==0)
        {
            tree = false;
            break;
        }
        else if(!visit[it])
            dfs(it);
    }
    counti++;
    topo[node] = counti;
}

int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        edge.push_back({a,b});
    }
    for(i=0;i<n;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    if(tree)
    {
        cout<<"1\n";
        for(i=0;i<m;i++)
            cout<<"1 ";
    }
    else
    {
        cout<<"2\n";
        for(auto it: edge)
        {
            int q = it.first;
            int w = it.second;
            if(q<w)
                cout<<"1 ";
            else
                cout<<"2 ";
        }
    }
    return 0;
}