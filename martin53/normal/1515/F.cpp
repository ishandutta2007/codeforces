#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n,m,x;

long long inp[nmax];

vector< pair<int,int> > adj[nmax];

int parent[nmax];

int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
set< pair<long long,int> > active;

int id[nmax];

int main()
{
    scanf("%i%i%i",&n,&m,&x);

    long long sum=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&inp[i]);
        sum+=inp[i];
    }

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    if(sum<1LL*x*(n-1))
    {
        printf("NO\n");
        return 0;
    }

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=n;i++)
    {
        active.insert({inp[i],i});
    }

    printf("YES\n");

    for(int i=1;i<n;i++)
    {
        /*
        cout<<"given: ";for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cout<<root(i)<<" ";cout<<endl;
        cout<<"---"<<endl;
        */

        set< pair<long long,int> >::iterator it=active.end();
        it--;

        int u=(*it).second;

        //cout<<"u= "<<u<<endl;

        while(id[u]<adj[u].size())
        {
            int v=adj[u][id[u]].first;

            int to_outp=adj[u][id[u]].second;

            id[u]++;

            if(root(u)==root(v))continue;

            printf("%i\n",to_outp);

            int u_root=root(u);
            int v_root=root(v);

            active.erase({inp[u_root],u_root});
            active.erase({inp[v_root],v_root});

            if(adj[u_root].size()<adj[v_root].size())swap(u_root,v_root);

            for(auto w:adj[v_root])adj[u_root].push_back(w);

            parent[v_root]=u_root;
            inp[u_root]=inp[u_root]+inp[v_root]-x;
            inp[v_root]=0;

            active.insert({inp[u_root],u_root});
            break;
        }
    }

    return 0;
}