#include <bits/stdc++.h>
using namespace std;
long long dist[200005],N;
vector<int>ed[200005];
vector<int>cst[200005];
const long long INF=1000000000000000LL;
void dijkstra (int S)
{
    priority_queue<pair<long long,int> >q;
    int i,nn;
    for(i=1;i<=N+N;++i)
        dist[i]=INF;
    dist[S]=0;
    q.push(make_pair(0,S));
    while(!q.empty())
    {
        int nod=q.top().second;
        long long distc=-q.top().first;
        q.pop();
        if(dist[nod]<distc)
            continue;
        for(i=0;i<ed[nod].size();++i)
        {
            nn=ed[nod][i];
            if(dist[nod]+cst[nod][i] < dist[nn])
            {
                dist[nn] = dist[nod]+cst[nod][i];
                q.push(make_pair(-dist[nn],nn));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,m,k=0,q,n1,n2;
    cin>>N>>m;
    for(i=1;i<=N;++i)
    {
        ed[i].push_back(i+N);
        cst[i].push_back(0);
    }
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ed[a].push_back(b);
        cst[a].push_back(c);
        ed[b+N].push_back(a+N);
        cst[b+N].push_back(c);
    }
    dijkstra(1);
    for(i=2+N;i<=N+N;++i)
    {
        if(dist[i]==INF)
            cout<<"-1 ";
        else
            cout<<dist[i]<<' ';
    }
    return 0;
}