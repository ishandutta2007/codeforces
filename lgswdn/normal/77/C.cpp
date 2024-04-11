#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;} 

int n,k[N],f[N],g[N],s;
void dfs(int u,int fa) {
	priority_queue<int>q;
	g[u]=k[u]; int sumg=0;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		dfs(v,u);
		q.push(f[v]);
		sumg+=g[v];
	}
	for(;g[u]>1&&!q.empty();q.pop()) f[u]+=(q.top()+1),g[u]--;
	f[u]+=min(sumg,g[u]-1)*2, g[u]-=min(sumg,g[u]-1);
	f[u]++, g[u]--;
}

signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v), add(u,v), add(v,u);
	scanf("%lld",&s);
	k[s]++;
	dfs(s,0);
	printf("%I64d",f[s]-1);
	return 0;
}