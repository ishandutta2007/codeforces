#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42,SZ=30,inf=1e9;
string inp;
int n;
int seen[SZ];
int dist[nmax],parent[nmax];
vector< pair<int/*from*/,int/*to*/> > edges;
int flow[nmax][nmax],cost[nmax][nmax];
void run()
{
    for(int i=0;i<nmax;i++)
        dist[i]=inf;
    dist[0]=0;
    for(int i=0;i<n+27;i++)
        for(auto k:edges)
        if(flow[k.first][k.second])
        {
            if(dist[k.first]+cost[k.first][k.second]<dist[k.second])
            {
            parent[k.second]=k.first;
            dist[k.second]=dist[k.first]+cost[k.first][k.second];
            }
        }
}
int main()
{
cin>>inp;
cin>>n;
string now;
int lim;
for(int i=1;i<=n;i++)
{
    cin>>now>>lim;
    flow[0][i]=lim;
    cost[0][i]=i;
    cost[i][0]=-i;
    edges.push_back({0,i});
    edges.push_back({i,0});
    memset(seen,0,sizeof(seen));
    for(auto k:now)
        seen[k-'a'+1]++;
    for(int j=1;j<=26;j++)
        if(seen[j])
        {
        flow[i][j+n]=seen[j];
        cost[i][j+n]=0;
        cost[j+n][i]=0;
        edges.push_back({i,j+n});
        edges.push_back({j+n,i});
        }
}
    memset(seen,0,sizeof(seen));
    for(auto k:inp)
        seen[k-'a'+1]++;
    for(int j=1;j<=26;j++)
        if(seen[j])
        {
        flow[j+n][n+27]=seen[j];
        cost[j+n][n+27]=0;
        cost[n+27][j+n]=0;
        edges.push_back({j+n,n+27});
        edges.push_back({n+27,j+n});
        }
/*
for(int i=0;i<nmax;i++)
    for(int j=0;j<nmax;j++)
    if(flow[i][j]||cost[i][j])
    {
    cout<<i<<" "<<j<<" -> "<<flow[i][j]<<" "<<cost[i][j]<<endl;
    }
*/
int f=0,c=0;
while(1)
{
    run();
    if(dist[n+27]==inf)break;
    int where=n+27;
    while(where)
    {
        flow[parent[where]][where]--;
        flow[where][parent[where]]++;
        c=c+cost[parent[where]][where];
        where=parent[where];
    }
    f++;
}
//cout<<f<<" "<<c<<endl;
if(f!=inp.size())cout<<-1<<endl;
else cout<<c<<endl;
return 0;
}