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

const int N=200100;

const int inf=1<<29;
const int V=201000, E=5010000;
int s,t,vtot;
struct edge{int v,ne;ll f;}e[E*2];int g[V],et;
void ae(int u,int v,ll f){
	e[et]={v,g[u],f};g[u]=et++;
	e[et]={u,g[v],0};g[v]=et++;
}
int d[V],cu[V];
bool lb(){
	rep(i,1,vtot+1)d[i]=0,cu[i]=g[i];
	static int qu[V];
	int p=0,q=0;
	qu[q++]=s,d[s]=1;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].ne)if(e[i].f && !d[e[i].v]){
			d[e[i].v]=d[u]+1;
			if(e[i].v==t)return 1;
			qu[q++]=e[i].v;
		}
	}return 0;
}
ll aug(int u,ll m){
	if(u==t)return m;
	ll su=0,f;
	for (int i=cu[u];~i;cu[u]=i=e[i].ne)if(e[i].f && d[e[i].v]==d[u]+1){
		f=aug(e[i].v,min(m,e[i].f));
		e[i].f-=f; e[i^1].f+=f;
		m-=f; su+=f;
		if(!m)break;
	}
	if(!su)d[u]=-1;
	return su;
}
ll dinic(){
	ll su=0;
	while(lb())su+=aug(s,inf);
	return su;
}
void init(){
	rep(i,1,vtot+1)g[i]=-1;
	et=0;
}

int n,a[N];
VI dd[N];
void solve() {
	map<int,int> hs;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
		hs[a[i]]=i;
	}
	vtot=4*n+2; s=4*n+1; t=4*n+2;
	init();
	rep(i,1,n+1) {
		int i1=4*i-3,i2=4*i-2;
		int o1=4*i-1,o2=4*i;
		ae(i2,i1,inf);
		ae(o2,o1,inf);
		ae(i1,o1,inf);
		ae(i2,o2,inf);
		ae(o2,i1,inf);
		ae(i1,i2,1);
		ae(i2,t,2);
		ae(s,o1,2);
		ae(o1,o2,1);
		for (auto y:dd[a[i]]) if (y!=a[i]&&hs.count(y)) {
			int j=hs[y];
			ae(4*j-1,4*i-3,inf);
			ae(4*j,4*i-2,inf);
		}
	}
	ll ans=dinic();
	printf("%lld\n",ans-n);
}
int _;
int main() {
	int M=50000;
	for (int i=1;i<=M;i++) for (int j=i;j<=M;j+=i)
		dd[j].pb(i);
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}