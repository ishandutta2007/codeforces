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

const int inf=0x20202020;
namespace mincost {
	const int V=101000,E=10010000,_inf=0x20;
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

const int N=110;
int n,m,k,c,d,a[N],x[N],y[N],pos[N][N],tot;
int main() {
	scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
	int TM=101;
	for (int i=1;i<=k;i++) scanf("%d",a+i);
	rep(i,0,m) {
		scanf("%d%d",x+i,y+i);
	}
	rep(i,1,n+1) rep(j,0,TM+1) {
		pos[i][j]=tot++;
	}
	mincost::init(tot,tot+1,tot+2);
	rep(i,1,n+1) rep(j,0,TM) {
		mincost::add(pos[i][j],pos[i][j+1],inf,0);
	}
	rep(i,1,k+1) mincost::add(tot,pos[a[i]][0],1,0);
	rep(j,0,TM+1) mincost::add(pos[1][j],tot+1,inf,c*j);
	rep(i,0,m) {
		rep(j,0,TM) rep(cnt,0,k+1) {
			mincost::add(pos[x[i]][j],pos[y[i]][j+1],1,d*(2*cnt+1));
			mincost::add(pos[y[i]][j],pos[x[i]][j+1],1,d*(2*cnt+1));
		}
	}
	mincost::solve();
	printf("%d\n",mincost::cost);
}