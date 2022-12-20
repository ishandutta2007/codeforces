#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,m;
vector< pair<int/*where*/,long long/*cost*/> >adj[nmax];
priority_queue< pair<long long/*dist*/,int/*id*/> > pq;
long long arr[nmax],ans[nmax];
int main()
{
scanf("%i%i",&n,&m);
long long x,y,w;
for(int i=1;i<=m;i++)
{
    scanf("%lld%lld%lld",&x,&y,&w);
    adj[x].push_back({y,w});
    adj[y].push_back({x,w});
}
for(int i=1;i<=n;i++)
{
    scanf("%lld",&arr[i]);
    pq.push({-arr[i],i});
}
for(int i=1;i<=n;i++)ans[i]=1e18;
while(pq.size())
{
    pair<long long/*dist*/,int/*id*/> now=pq.top();
    pq.pop();
    now.first=-now.first;
    if(ans[now.second]<=now.first)continue;
    ans[now.second]=now.first;
    for(auto k:adj[now.second])
        pq.push({-(now.first+2*k.second),k.first});
}
for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
return 0;
}