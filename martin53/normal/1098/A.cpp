#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,inf=1e9+42;
int n;
vector<int> adj[nmax];
int sum[nmax];
int depth[nmax];
int parent[nmax];
int main()
{
scanf("%i",&n);
int x;
for(int i=2;i<=n;i++)
{
    scanf("%i",&x);
    depth[i]=depth[x]+1;
    parent[i]=x;
    adj[i].push_back(x);
    adj[x].push_back(i);
}
for(int i=1;i<=n;i++)scanf("%i",&sum[i]);

for(int i=1;i<=n;i++)
    if(sum[i]==-1)
    {
        int mini=inf,maxi=0;
        for(auto k:adj[i])
            if(depth[k]==depth[i]+1)mini=min(mini,sum[k]);
            else maxi=sum[k];
        if(mini==inf)mini=maxi;
        if(mini<maxi)
        {
            printf("%i\n",-1);
            return 0;
        }
        sum[i]=mini;
    }
long long ans=0;
for(int i=1;i<=n;i++)
    ans=ans+sum[i]-sum[parent[i]];
printf("%lld\n",ans);
return 0;
}