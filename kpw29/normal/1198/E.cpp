#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
const int inf = 1e9+9;
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

set <int> xlines;
set <int> ylines;
//borrowed from whxtdy
namespace mincost {
	const int V=101000,E=10010000,_inf=INT_MAX;
	int dis[V],q[V*30],vis[V],fst[V],pre[V],nxt[E],y[E],f[E],c[E],S,T,flow,cost,tot,tn;
	void init(int s,int t,int Tn) {
		tot=1; tn=Tn;
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;
	}
	void add(int u,int v,int ff,int cc) {
		tot++;y[tot]=v;nxt[tot]=fst[u];f[tot]=ff;c[tot]=cc;fst[u]=tot;
		tot++;y[tot]=u;nxt[tot]=fst[v];f[tot]=0;c[tot]=-cc;fst[v]=tot;
	}
	bool spfa() {
		rep(i,0,tn) dis[i]=inf,vis[i]=0,pre[i]=0;
		dis[S]=0;q[0]=S;vis[S]=1;
		int t=1;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) {
				int v=y[j];
				if (f[j]&&dis[v]>dis[u]+c[j]) {
					dis[v]=dis[u]+c[j];
					pre[v]=j;
					if (!vis[v]) vis[v]=1,q[t++]=v;
				}
			}
			vis[u]=0;
		}
		return dis[T]!=inf;
	}
	void augment() {
		int p=T,_f=inf;
		while (pre[p]) _f=min(_f,f[pre[p]]),p=y[pre[p]^1];
		flow+=_f;cost+=_f*dis[T];
		p=T;
		while (pre[p]) f[pre[p]]-=_f,f[pre[p]^1]+=_f,p=y[pre[p]^1];
	}
	void solve() {
		flow=0,cost=0;
		while (spfa()) augment();
	}
}

int X1[51], X2[51], Y1[51], Y2[51], n, m;
vector <int> x, y;

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, m) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		X1[i] = x1; X2[i] = x2;
		Y1[i] = y1; Y2[i] = y2;
		
		xlines.insert(x1);
		if (x1 > 1) xlines.insert(x1 - 1);
		xlines.insert(x2);
		if (x2 < n) xlines.insert(x2 + 1);
		
		ylines.insert(y1);
		if (y1 > 1) ylines.insert(y1 - 1);
		ylines.insert(y2);
		if (y2 < n) ylines.insert(y2 + 1);
	}
	
	xlines.insert(1); xlines.insert(n + 1);
	ylines.insert(1); ylines.insert(n + 1);
	int LEFT = (int)xlines.size();
	int RIGHT = (int)ylines.size();
	for (auto u : xlines) x.pb(u);
	for (auto u : ylines) y.pb(u);
	
	mincost::init(0, LEFT + RIGHT + 1, LEFT + RIGHT + 5);
	ll value = 0;
	for (int i = 0; i + 1 < LEFT; ++i) {
		int iks = x[i];
		for (int j = 0; j + 1 < RIGHT; ++j) {
			int igr = y[j];
			bool needs = false;
			for (int rect = 1; rect <= m; ++rect)
			{
				if (X1[rect] <= iks && iks <= X2[rect] && Y1[rect] <= igr && igr <= Y2[rect]) {
					needs = true;
					break;
				}
			}
			
			if (needs)
			{
				int kosz = min(x[i + 1] - x[i], y[j + 1] - y[j]);
				mincost::add(i + 1, j + 1 + LEFT, inf, 0);
				value += kosz;
			}
		}
	}
	
	FOR(i, 1, LEFT - 1) mincost::add(0, i, x[i] - x[i-1], 0);
	FOR(i, 1, RIGHT - 1) mincost::add(LEFT + i, LEFT+RIGHT+1, y[i] - y[i-1], 0);
	mincost::solve();
	cout << mincost::flow;
}