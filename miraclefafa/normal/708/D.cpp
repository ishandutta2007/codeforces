#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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

namespace mincost {
	const int V=210,E=40000,inf=0x20202020,_inf=0x20;
	int dis[V],q[V*300],vis[V],fst[V],pre[V],nxt[E],y[E],f[E],c[E],S,T,flow,cost,tot,tn;
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

int n,m,u,v,c,f,ret,d[110];
int main() {
	scanf("%d%d",&n,&m);
	mincost::init(n,n+1,n+2);
	rep(i,0,m) {
		scanf("%d%d%d%d",&u,&v,&f,&c); // f  c dangqian liuliang
		--u; --v;
		if (f>=c) {
			d[u]+=c;
			d[v]-=c;
			mincost::add(u,v,f-c,1);
			mincost::add(u,v,0x20202020,2);
			mincost::add(v,u,c,1);
		} else {
			d[u]+=c;
			d[v]-=c;
			ret+=c-f;
			mincost::add(v,u,c-f,0);
			mincost::add(v,u,f,1);
			mincost::add(u,v,0x20202020,2);
		}
	}
	mincost::add(n-1,0,0x20202020,0);
	rep(i,0,n) if (d[i]<0) mincost::add(n,i,-d[i],0); else mincost::add(i,n+1,d[i],0);
	mincost::solve();
	printf("%d\n",mincost::cost+ret);
}