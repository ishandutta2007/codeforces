#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=2e5+5;
int n,k,fa[N],s[N],a0[N],a1[N];
ll dp[N][2];
vector<int> G[N];
priority_queue<ll> pq;
void dfs(int u) {
	int c=G[u].size();
	ll sum=0;
	for(auto v:G[u]) {
		a0[v]=a0[u]/c;
		a1[v]=(a1[u]+c-1)/c;
		dfs(v);
		sum+=dp[v][0];
	}
	while(pq.size()) pq.pop();
	for(auto v:G[u]) pq.push(dp[v][1]-dp[v][0]);
	dp[u][0]=sum+1ll*s[u]*a0[u];
	if(c) fr(i,1,a0[u]%c) dp[u][0]+=pq.top(),pq.pop();

	while(pq.size()) pq.pop();
	for(auto v:G[u]) pq.push(dp[v][1]-dp[v][0]);
	dp[u][1]=sum+1ll*s[u]*a1[u];
	if(c) {
		if(a1[u]/c>a0[u]/c) {
			for(auto v:G[u])
				dp[u][1]+=dp[v][1]-dp[v][0];
		} else if(c) fr(i,1,a1[u]%c) dp[u][1]+=pq.top(),pq.pop();
	}
}
int main() {
	int T=read();
	while(T--) {
		n=read(); k=read();
		fr(i,1,n) G[i].clear();
		fr(i,2,n) fa[i]=read(),G[fa[i]].push_back(i);
		fr(i,1,n) s[i]=read();
		a0[1]=a1[1]=k;
		dfs(1);
		printf("%lld\n",dp[1][0]);
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}