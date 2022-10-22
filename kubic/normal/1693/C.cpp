#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
const int INF=1e9;
int n,m,dp[N],cnt[N];bool vs[N];vector<int> e[N];
struct Node {int u,w;bool operator < (Node t) const {return w>t.w;}};
priority_queue<Node> q;
int main()
{
	scanf("%d %d",&n,&m);q.push((Node) {n,0});
	for(int i=1;i<n;++i) dp[i]=INF;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[v].pb(u),++cnt[u];
	while(!q.empty())
	{
		Node t=q.top();q.pop();
		int u=t.u,w;if(vs[u]) continue;vs[u]=1;
		for(auto v:e[u])
		{
			--cnt[v];w=dp[u]+cnt[v]+1;
			if(w<dp[v]) q.push((Node) {v,dp[v]=w});
		}
	}printf("%d\n",dp[1]);return 0;
}