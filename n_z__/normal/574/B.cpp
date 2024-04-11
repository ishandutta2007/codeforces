#include<bits/stdc++.h>
using namespace std;
#define int long long
int q[4001][4001],d[4001];
main()
{
    int n,m;
    cin>>n>>m;
    for(int x=1;x<=m;x++)
    {
        int u,v;
        cin>>u>>v;
        q[u][v]=q[v][u]=1;
        d[u]++;
        d[v]++;
    }
    int ans=1000000000;
    for(int x=1;x<=n;x++)
    for(int y=x+1;y<=n;y++)
    if(q[x][y])
    for(int z=y+1;z<=n;z++)
    if(q[x][z]&&q[y][z])
    {
        ans=min(ans,d[x]+d[y]+d[z]);
    }
    if(ans==1000000000)cout<<-1<<endl;
    else cout<<ans-6<<endl;
}