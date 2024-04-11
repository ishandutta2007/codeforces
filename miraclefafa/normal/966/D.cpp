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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
int n,m,u,v,pre[N],dis[N],q[N],f[N];
bool mark[N];
set<PII> E;
VI e[N],pt;
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
		E.insert(mp(u,v));
		E.insert(mp(v,u));
		if (u==1||v==1) mark[u]=1,mark[v]=1;
	}
	rep(i,1,n+1) dis[i]=n+1;
	dis[1]=0;
	int t=0;
	q[t++]=1;
	rep(i,0,t) {
		u=q[i];
		for (auto v:e[u]) if (dis[v]>dis[u]+1) {
			pre[v]=u;
			dis[v]=dis[u]+1;
			q[t++]=v;
		}
	}
//	printf("%d\n",dis[n]);
	if (dis[n]<=n) {
		u=n;
		while (u!=1) {
			pt.pb(u);
			u=pre[u];
		}
		pt.pb(1);
	}
	reverse(all(pt));
	for (auto u:e[1]) for (auto v:e[u]) if (!mark[v]) {
		if (pt.empty()||SZ(pt)>4) {
			pt=VI{1,u,v,1,n};
		}
	}
	if (pt.empty()||SZ(pt)>5) {
		mark[1]=0;
		rep(i,1,n+1) f[i]=i;
		for (auto p:E) {
			u=p.fi,v=p.se;
			if (mark[u]&&mark[v]) f[find(u)]=find(v);
		}
		rep(i,1,n+1) dis[i]=n+1;
		rep(i,1,n+1) if (mark[i]&&find(i)==i) {
			int t=0; dis[i]=0; q[t++]=i;
			rep(j,0,t) {
				u=q[j];
				for (auto v:e[u]) if (mark[v]&&dis[v]>dis[u]+1) {
					pre[v]=u;
					dis[v]=dis[u]+1;
					if (dis[v]==2) {
						pt=VI{1,i,u,v,i,n};
						goto end;
					}
					q[t++]=v;
				}
			}
			rep(x,1,t) rep(y,x+1,t) {
				u=q[x],v=q[y];
				if (!E.count(mp(u,v))) {
					pt=VI{1,u,i,v,u,n};
					goto end;
				}
			}
		}
	}
	end:;
	if (pt.empty()) {
		puts("-1");
	} else {
		printf("%d\n",SZ(pt)-1);
		rep(i,0,SZ(pt)) printf("%d ",pt[i]);
		puts("");
	}
}