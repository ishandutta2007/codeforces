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

const int N=501000;
int dep[N],p[N][22],n,go[N];
int ideg[N],odeg[N],f[N],ff[N],gg[N];
VI e[N],goup[N],godown[N],figoup[N],figodown[N];
map<int,int> zup[N],zdown[N];
vector<PII> turnd[N];
ll ans=1;

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

#define LOGN 19
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
int brh(int u,int v) { // v->u
	per(i,0,LOGN) if (dep[p[v][i]]>dep[u]) v=p[v][i];
	return v;
}

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	p[u][0]=f;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}

void failed() {
	puts("0");
	exit(0);
}

ll gao(int u,set<PII> &cc) {
	map<int,int> id;
	int m=0;
	for (auto v:e[u]) id[v]=++m;
	rep(i,1,m+1) ideg[i]=0,odeg[i]=0,f[i]=i;
	int hd=-1,tl=-1;
	for (auto p:cc) {
		int u=id[p.fi],v=id[p.se];
		++odeg[u]; ++ideg[v];
		if (find(u)==find(v)) failed();
		f[find(u)]=find(v);
	}
	rep(i,1,m+1) if (ideg[i]>1||odeg[i]>1) failed();
	if (ff[u]!=-1) hd=id[ff[u]];
	if (gg[u]!=-1) tl=id[gg[u]];
	if (hd!=-1&&ideg[hd]>0) failed();
	if (tl!=-1&&odeg[tl]>0) failed();
	int zz=0;
	rep(i,1,m+1) if (find(i)==i) zz++;
	if (hd!=-1&&tl!=-1&&find(hd)==find(tl)&&zz!=1) failed();
	if (hd!=-1) zz--; if (tl!=-1) zz--;
	ll fac=1;
	rep(i,1,zz+1) fac=fac*i%mod;
	return fac;
}

void solve(int u,int f) {
	map<int,int> pu,pd;
	for (auto x:goup[u]) pu[x]++;
	for (auto x:godown[u]) pd[x]++;
	for (auto v:e[u]) {
		if (v==f) continue;
		solve(v,u);
		for (auto x:zup[v]) pu[v]+=x.se;
		for (auto x:zdown[v]) pd[v]+=x.se;
	}
	if (SZ(pu)>1||SZ(pd)>1) failed();
	set<PII> cc;
	for (auto x:turnd[u]) cc.insert(x);
	if (!pu.empty()) cc.insert(mp(pu.begin()->fi,p[u][0]));
	if (!pd.empty()) cc.insert(mp(p[u][0],pd.begin()->fi));
	//printf("cc %d: %d %d\n",u,ff[u],gg[u]);
	//for (auto x:cc) printf("%d %d\n",x.fi,x.se);
	ans=ans*gao(u,cc)%mod;
	for (auto x:figoup[u]) pu[x]--;
	for (auto x:figodown[u]) pd[x]--;
	for (auto x:pu) if (x.se>0) zup[u].insert(x);
	for (auto x:pd) if (x.se>0) zdown[u].insert(x);
	//for (auto xx:zup[u]) printf("zz %d %d\n",xx.fi,xx.se);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) go[i]=-1;
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i,1,n+1) {
		int t;
		scanf("%d",&t);
		if (t) go[t]=i;
	}
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	rep(i,1,n+1) if (go[i]==i) failed();
	rep(i,1,n+1) ff[i]=gg[i]=-1;
	rep(i,1,n+1) if (go[i]!=-1) {
		int w=lca(i,go[i]);
		if (i!=w&&p[i][0]!=w) {
			goup[p[i][0]].pb(i);
			int bw=brh(w,i);
			figoup[bw].pb(brh(bw,i));
		}
		if (go[i]!=w&&p[go[i]][0]!=w) {
			godown[p[go[i]][0]].pb(go[i]);
			int bw=brh(w,go[i]);
			figodown[bw].pb(brh(bw,go[i]));
		}
		if (i!=w&&go[i]!=w) {
			ff[i]=p[i][0]; gg[go[i]]=p[go[i]][0];
			turnd[w].pb(mp(brh(w,i),brh(w,go[i])));
		} else if (i==w) {
			ff[i]=brh(w,go[i]); gg[go[i]]=p[go[i]][0];
		} else {
			ff[i]=p[i][0]; gg[go[i]]=brh(w,i);
		}
	}
	/*rep(i,1,n+1) {
		for (auto x:goup[i]) printf("up %d %d\n",i,x);
		for (auto x:figoup[i]) printf("down %d %d\n",i,x);
	}*/
	solve(1,0);
	printf("%lld\n",ans);
}