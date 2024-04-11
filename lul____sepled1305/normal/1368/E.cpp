#include<bits/stdc++.h>
using namespace std;
int T;

void bfs(vector<int> topo, vector<int> G[],int gr[])
{
    while(!topo.empty())
    {
        int node = topo.back();
        topo.pop_back();
        if(gr[node]==0)
            gr[node] = 1;
        for(auto it: G[node])
        {
            if(gr[node]==2)
            {
                gr[it] = 3;
            }
            if(gr[node]==1)
            {
                if(gr[it]==2 || gr[it]==0 || gr[it]==1)
                    gr[it]=2;
                else
                    gr[it]=3;
            }
            if(gr[node]==3)
            {
                if(gr[it]==0 || gr[it]==1)
                    gr[it]=1;
                else if(gr[it]==3)
                    gr[it]=3;
                else
                    gr[it]=2;
            }
        }
    }
}

void dfs(int node,vector<int> G[],vector<int> &topo, bool visit[])
{
    if(!visit[node])
    {
        visit[node] = true;
        for(auto it: G[node])
            dfs(it,G,topo,visit);
        topo.push_back(node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        int n,m,i,counti=0;
        cin>>n>>m;
        bool beg[n];
        bool visit[n];
        int gr[n];
        vector<int> graph[n];
        vector<int> topo;
        for(i=0;i<n;i++)
        {
            beg[i] = true;
            visit[i] = false;
            gr[i] = 0;
        }
        for(i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            beg[b] = false;
            graph[a].push_back(b);
        }
        for(i=0;i<n;i++)
        {
            if(beg[i])
                dfs(i,graph,topo,visit);
        }
        bfs(topo,graph,gr);
        for(i=0;i<n;i++)
        {
            if(gr[i]==3)
                counti++;
        }
        cout<<counti<<"\n";
        for(i=0;i<n;i++)
            if(gr[i]==3)
                cout<<i+1<<" ";
        cout<<"\n";
    }
    return 0;
}