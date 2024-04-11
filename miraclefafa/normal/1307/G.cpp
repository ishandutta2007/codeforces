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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

vector<pair<int,ll>> ans;


namespace mincost {
	const int V=250,E=40000,inf=0x20202020,_inf=0x20;
	const ll inff=1ll<<60;
	ll dis[V],c[E],cost;
	int q[V*30],vis[V],fst[V],pre[V],nxt[E],y[E],f[E],S,T,flow,tot,tn;
	void init(int s,int t,int Tn) {
		tot=1; tn=Tn;
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;
	}
	void add(int u,int v,int ff,ll cc) {
		tot++;y[tot]=v;nxt[tot]=fst[u];f[tot]=ff;c[tot]=cc;fst[u]=tot;
		tot++;y[tot]=u;nxt[tot]=fst[v];f[tot]=0;c[tot]=-cc;fst[v]=tot;
	}
	bool spfa() {
		rep(i,0,tn) dis[i]=inff,vis[i]=0,pre[i]=0;
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
		return dis[T]!=inff;
	}
	void augment() {
		int p=T,_f=inf;
		while (pre[p]) _f=min(_f,f[pre[p]]),p=y[pre[p]^1];
		flow+=_f;cost+=_f*dis[T];
		p=T;
		while (pre[p]) f[pre[p]]-=_f,f[pre[p]^1]+=_f,p=y[pre[p]^1];
		ans.pb(mp(flow,cost));
	}
	void solve() {
		flow=0,cost=0;
		while (spfa()) augment();
	}
}

int n,m,u,v,w,q,x;
int main() {
	scanf("%d%d",&n,&m);
	mincost::init(0,n-1,n);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		mincost::add(u-1,v-1,1,w);
	}
	mincost::solve();
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d",&x);
		db r=1e30;
		for (auto y:ans) r=min(r,1.*(y.se+x)/y.fi);
		printf("%.10f\n",r);
	}
}