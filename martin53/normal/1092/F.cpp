#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
vector<int> adj[nmax];
int arr[nmax];
long long sum[nmax];
long long ans=0,total=0;
void dfs(int node,int par)
{
    sum[node]=arr[node];
    for(auto k:adj[node])
        if(k!=par)
        {
            dfs(k,node);
            sum[node]+=sum[k];
        }
}

void solve(int node,int par,long long now)
{
    ans=max(ans,now);
    for(auto k:adj[node])
        if(k!=par)//move root to k
        {
            solve(k,node,now-sum[k]+(total-sum[k]));
        }
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
scanf("%i",&arr[i]);
total=total+arr[i];
}
int x,y;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}

dfs(1,1);
for(int i=2;i<=n;i++)
    ans=ans+sum[i];

solve(1,1,ans);

printf("%lld\n",ans);
return 0;
}