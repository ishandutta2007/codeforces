#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define int long long

const int N = 1.5e5 + 5,MOD = 998244353;
int n,m;
ll ans[N];
ll qpow(ll a,int x) {
	ll res = 1;
	for(;x;x >>= 1,a = a * a % MOD)
		if(x & 1) res = res * a % MOD;
	return res;
}
int fir[N],to[N << 1],eds,nxt[N << 1];
void addedge(int u,int v) {
	to[++eds] = v;
	nxt[eds] = fir[u];
	fir[u] = eds;
}
vector<int> buc[N];

struct Event {
	int op,u,d;
} q[N];
int rt,mx,siz[N],vis[N],bel[N],rsiz[N],sizz[N];
ll f[N];
void getrt(int u,int fa,int nds) {
	int res = 0;
	siz[u] = 1;
	foredge(i,u,v) if(v != fa && !vis[v]) {
		getrt(v,u,nds);
		siz[u] += siz[v];
		res = max(res,siz[v]);
	}
	res = max(res,nds-siz[u]);
	if(res < mx) mx = res,rt = u;
}
vector<int> tmp;
void dfs(int u,int fa) {
	siz[u] = 1 + rsiz[u];
	sizz[u] = 1;
	foredge(i,u,v) if(!vis[v] && v != fa) {
		bel[v] = bel[u]; dfs(v,u);
		siz[u] += siz[v];
		sizz[u] += sizz[v];
	}
	for(auto i : buc[u]) tmp.push_back(i);
}
void divide(int u,int nds) {
	mx = nds; getrt(u,0,nds);
	vis[u = rt] = 1;
	foredge(i,u,v) if(!vis[v])
		bel[v] = v,dfs(v,u);
	siz[u] = n;
	for(auto i : buc[u]) tmp.push_back(i);
	sort(tmp.begin(),tmp.end());
	ll res = 0,res2 = 0;
	for(auto i : tmp) {
		if(q[i].op == 1) {
			(res += q[i].d * siz[q[i].u]) %= MOD;
			if(q[i].u != u) (f[bel[q[i].u]] -= q[i].d * siz[q[i].u]) %= MOD;
			else (res2 -= q[i].d) %= MOD;
		} else {
			if(q[i].u == u) (ans[i] += res) %= MOD;
			else (ans[i] += res + f[bel[q[i].u]] + res2 * siz[bel[q[i].u]] % MOD) %= MOD;
		}
	}
	foredge(i,u,v) if(!vis[v]) f[v] = 0;
	tmp.clear();
	foredge(i,u,v) if(!vis[v]) {
		rsiz[v] += n-siz[v];
		divide(v,sizz[v]);
	}
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i = 1,u,v;i < n;++i) {
		scanf("%lld%lld",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	//cout << qpow(7,MOD-2) * 5 % MOD << endl;
	fr(i,1,m) {
		scanf("%lld%lld",&q[i].op,&q[i].u);
		if(q[i].op == 1) scanf("%lld",&q[i].d);
		buc[q[i].u].push_back(i);
	}
	divide(1,n);
	ll iv = qpow(n,MOD-2);
	fr(i,1,m) if(q[i].op == 2)
		printf("%lld\n",(ans[i] * iv % MOD + MOD) % MOD);
	return 0;
}