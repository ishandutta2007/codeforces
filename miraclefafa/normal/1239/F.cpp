#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;

int pt[N],vis[N],par[N],dep[N],mark[N],n,m,suc,_,q[N];
VI ps,e[N];

int sz[N],isr[N],l[N],r[N],totd,rt;
VI lef,vec;
PII pz[N];

void output(VI x) {
	puts("Yes");
	rep(i,1,n+1) mark[i]=0;
	for (auto u:x) mark[u]=1;
	printf("%d\n",n-SZ(x));
	rep(i,1,n+1) if (!mark[i]) printf("%d ",i);
	puts("");
	suc=1;
}

bool findp(int u,int d,int ww) {
	pt[d]=u; vis[u]=1;
	if (u==ww) {
		ps=VI(pt,pt+d+1);
		return 1;
	}
	for (auto v:e[u]) {
		if (!vis[v]) {
			if (findp(v,d+1,ww)) return 1;
		}
	}
	return 0;
}

void dfs(int u,int f) {
	vis[u]=1; sz[u]=isr[u];
	l[u]=++totd;
	if (isr[u]) lef.pb(u);
	vec.pb(u);
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		sz[u]+=sz[v];
	}
	r[u]=totd;
}

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) e[i].clear(),vis[i]=0;
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	if (m==0) return;
	rep(i,1,n+1) if (SZ(e[i])%3==0) {
		output(VI{i}); return;
	}
	VI pc1;
	rep(v,1,n+1) if (SZ(e[v])%3==1) pc1.pb(v);
	rep(i,1,n+1) dep[i]=n+1;
	auto gao=[&](int u) {
		int t=0;
		q[t++]=u; dep[u]=0;
		VI x,y;
		rep(i,0,t) {
			int u=q[i];
			for (auto v:e[u]) {
				if (dep[v]==n+1) {
					dep[v]=dep[u]+1;
					par[v]=u;
					q[t++]=v;
				} else if (v!=par[u]) {
					while (u!=v) {
						if (dep[u]>dep[v]) {
							x.pb(u); u=par[u];
						} else {
							y.pb(v); v=par[v];
						}
					}
					x.pb(u);
					reverse(all(y));
					for (auto w:y) x.pb(w);
					if (SZ(x)==n) return 0;
					ps=x;
					return 1;
				}
			}
		}
		return 0;
	};
	if (SZ(pc1)>=2) {
		int t=0;
		q[t++]=pc1[0];
		dep[pc1[0]]=0;
		rep(i,0,t) {
			int u=q[i];
			if (i!=0&&SZ(e[u])%3==1) {
				ps.clear();
				while (1) {
					ps.pb(u);
					if (u==pc1[0]) break;
					u=par[u];
				}
				break;
			}
			for (auto v:e[u]) if (dep[v]==n+1) {
				dep[v]=dep[u]+1;
				par[v]=u;
				q[t++]=v;
			}
		}
		if (SZ(ps)==m+1) return;
		output(ps);
	} else if (SZ(pc1)==0) {
		if (gao(1)) {
			output(ps);
		}
		return;
	} else {
		rt=pc1[0];
		rep(i,1,n+1) vis[i]=0,isr[i]=0;
		for (auto v:e[rt]) {
			isr[v]=1;
			e[v].erase(find(all(e[v]),rt));
		}
		rep(i,1,n+1) if (dep[i]==n+1&&i!=rt) {
			if (gao(i)) {
				output(ps);
				return;
			}
		}
		assert(SZ(e[rt])>=4);
		int tt=0;
		for (auto v:e[rt]) if (!vis[v]) {
			lef.clear(); vec.clear();
			totd=0;
			dfs(v,-1);
			if (SZ(lef)<=3) pz[tt++]=mp(lef[0],lef[1]);
			else {
				bool suc=0;
				for (auto u:vec) if (isr[u]>=2&&SZ(lef)-isr[u]>=2) {
					suc=1;
					VI v1,v2;
					for (auto v:lef) {
						if (l[u]<=l[v]&&r[v]<=r[u]) v1.pb(v);
						else v2.pb(v);
					}
					pz[tt++]=mp(v1[0],v1[1]);
					pz[tt++]=mp(v2[0],v2[1]);
					break;
				}
				if (!suc) {
					pz[tt++]=mp(lef[0],lef[1]);
				}
			}
		}
		if (tt>=2) {
			VI r; r.pb(rt);
			rep(i,1,n+1) vis[i]=0;
			findp(pz[0].fi,0,pz[0].se);
			for (auto x:ps) r.pb(x);
			rep(i,1,n+1) vis[i]=0;
			findp(pz[1].fi,0,pz[1].se);
			for (auto x:ps) r.pb(x);
			if (SZ(r)!=n) {
				output(r);
			} else {
				return;
			}
		} else {
			return;
		}
	}
}

int main() {
	scanf("%d",&_);
	for (;_;_--) {
		suc=0;
		solve();
		if (!suc) puts("No");
	}
}