//did not work
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector< pair<int/*to*/,int/*cost*/> > adj[nmax];
long long dist[nmax];
int parent[nmax];
priority_queue< pair<long long/*cost*/,int/*to*/> > work;
bool done[nmax];
int main()
{
    scanf("%i%i",&n,&m);
    int u,v,c;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&u,&v,&c);
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    work.push({0,1});

    for(int i=2;i<=n;i++)
        dist[i]=1e18;

    while(work.size())
    {
        long long cost=-work.top().first;
        int now=work.top().second;
        work.pop();
        if(done[now])continue;
        done[now]=1;

        for(auto k:adj[now])
            if(dist[k.first]>dist[now]+k.second)
            {
                dist[k.first]=dist[now]+k.second;
                parent[k.first]=now;

                work.push({-(dist[now]+k.second),k.first});
            }
    }
    if(parent[n]==0)
    {
        printf("-1");
        return 0;
    }

    vector<int> out={};
    int now=n;
    while(now!=1)
    {
        out.push_back(now);
        now=parent[now];
    }

    out.push_back(1);

    reverse(out.begin(),out.end());

    for(auto k:out)
        printf("%i ",k);
    return 0;
}