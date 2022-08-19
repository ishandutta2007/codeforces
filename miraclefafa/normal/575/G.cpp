#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>
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
// head

const int N=101000;
int n,m,u,v,w,vis[N],dis[N],valw[N],nxtr[N],dis2[N];
VI pth,r[N];
vector<PII> e[N];
PII nxt[N],val[N];
queue<int> q;
void dfs(int u) {
	for (auto p:e[u]) if (p.se==0) {
		int v=p.fi;
		if (mp(dis[u],valw[u])<mp(dis[v],valw[v])) {
			dis[v]=dis[u]; valw[v]=valw[u];
			nxt[v]=mp(0,u);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
		if (w==0) r[v].pb(u),r[u].pb(v);
	}
	vis[0]=0;
	q.push(0);
	rep(dist,0,n+1) {
		VI cand;
		while (!q.empty()&&dis[q.front()]==dist) {
			int u=q.front(); q.pop();
			for (auto p:e[u]) {
				int v=p.fi,w=p.se;
				if (!vis[v]) {
					vis[v]=1; dis[v]=dis[u]+1; q.push(v);
					nxt[v]=mp(w,u); val[v]=mp(w,valw[u]);
					cand.pb(v);
				}
				if (dis[v]==dis[u]+1) {
					if (mp(w,valw[u])<val[v]) {
						val[v]=mp(w,valw[u]);
						nxt[v]=mp(w,u);
					}
				}
			}
		}
		vector<PII> cret;
		for (auto p:cand) cret.pb(val[p]);
		sort(all(cret)); cret.erase(unique(all(cret)),cret.end());
		for (auto p:cand) valw[p]=lower_bound(all(cret),val[p])-cret.begin();
	}
	rep(i,0,n) vis[i]=0; vis[n-1]=1;
	q.push(n-1);
	while (!q.empty()) {
		u=q.front(); q.pop();
		for (auto v:r[u]) if (!vis[v]) {
			vis[v]=1; q.push(v); nxtr[v]=u; dis2[v]=dis2[u]+1;
		}
	}
	auto mv=mp(mp(dis[n-1],valw[n-1]),mp(0,n-1));
	rep(i,0,n) if (vis[i]) {
		mv=min(mv,mp(mp(dis[i],valw[i]),mp(dis2[i],i)));
	}
//	printf("%d %d %d\n",mv.fi.fi,mv.fi.se,mv.se);
	u=mv.se.se;
	bool led=1;
	while (u!=0) {
		pth.pb(u);
		led&=nxt[u].fi==0;
		if (!led) putchar(nxt[u].fi+'0');
		u=nxt[u].se;
	}
	if (led) putchar('0'); puts("");
	reverse(all(pth));
	u=mv.se.se;
	while (u!=n-1) {
		u=nxtr[u];
		pth.pb(u);
	}
	printf("%d\n",SZ(pth)+1);
	putchar('0');
	for (auto p:pth) printf(" %d",p); puts("");
}