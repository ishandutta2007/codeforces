#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;

vector< pair<int,int> > adj[nmax],trav[nmax];

bool been[nmax];

stack<int> st;

void dfs(int node)
{
    if(been[node])return;

    been[node]=1;

    for(auto w:adj[node])
        dfs(w.first);

    st.push(node);
}

int component[nmax],pointer;

long long mem_dist[nmax];

void dfs_back(int node,long long d_now)
{
    if(component[node])return;

    //cout<<"dfs_back "<<node<<" "<<d_now<<endl;

    component[node]=pointer;
    mem_dist[node]=d_now;

    for(auto w:trav[node])
        dfs_back(w.first,d_now+w.second);
}

long long mem_g[nmax];

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;

        scanf("%i%i%i",&u,&v,&c);

        adj[u].push_back({v,c});

        trav[v].push_back({u,c});
    }

    for(int i=1;i<=n;i++)
        if(been[i]==0)dfs(i);

    while(st.size())
    {
        int node=st.top();

        st.pop();

        if(component[node])continue;

        pointer++;

        dfs_back(node,0);
    }

    //cout<<"mem_dist: ";for(int i=1;i<=n;i++)cout<<mem_dist[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++)
        for(auto j:trav[i])
            if(component[i]==component[j.first])
        {
            int u=i;
            int v=j.first;

            int c=component[u];

            long long d_now=mem_dist[u]+j.second-mem_dist[v];

            d_now=abs(d_now);

            //cout<<u<<" "<<v<<" -> "<<d_now<<endl;

            mem_g[c]=__gcd(mem_g[c],d_now);
        }

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<mem_g[i]<<endl;

    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int v,s,t;

        scanf("%i%i%i",&v,&s,&t);

        if(s%__gcd(mem_g[component[v]],1LL*t)==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}