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
array<int,3> E[N];
set<PII> g,qr[N];
set<int> fs[N],sp[N];
map<int,VI> fp[N];
int f[N],ff[N],ret[N];
int n,m,_,sz[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

vector<array<int,3>> e2;

void merge(int x,int y,int w) {
	e2.pb({w,x,y});
	//printf("zzzz %d %d %d\n",x,y,w);
	//printf("ff %d %d\n",x,y);
	x=ff[x]; y=ff[y];
	if (SZ(fs[x])<SZ(fs[y])) swap(x,y);
	assert(x!=y);
	for (auto p:fs[y]) {
		int u=ff[p],v=find(p);
		assert(u==y);
		if (sp[v].count(u)) sp[v].erase(u);
		sp[v].insert(x);
		if (fp[v].count(u)) fp[v].erase(u);
		fp[v][x].pb(p);
		ff[p]=x;
		fs[x].insert(p);
	}
	fs[y].clear();
}

void solve() {
	scanf("%d%d",&n,&m);
	g.clear();
	rep(i,1,n+1) qr[i].clear();
	rep(i,0,m) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i]={w,u,v};
		g.insert({u,v});
		g.insert({v,u});
		qr[u].insert({v,i});
		qr[v].insert({u,i});
		//printf("%d %d %d\n",u,v,w);
	}
	sort(E,E+m);
	rep(i,1,n+1) {
		sz[i]=1;
		f[i]=i;
		ff[i]=i;
		fp[i].clear();
		sp[i].clear();
		fs[i].clear();
		fp[i][i].pb(i);
		sp[i].insert(i);
		fs[i].insert(i);
	}
	e2.clear();
	rep(i,0,m) {
		int u=E[i][1],v=E[i][2];
		u=find(u); v=find(v);
		if (u==v) continue;
		if (sz[u]>sz[v]) swap(u,v);
		auto tmpu=sp[u];
		for (auto x:tmpu) {
			VI p0;
			if (ff[x]!=x) continue;
			for (auto uu:fp[u][x]) {
				VI p1;
				for (auto y:sp[v]) {
					if (y==x) continue;
					for (auto vv:fp[v][y]) {
						if (g.count({uu,vv}))
							continue;
						p1.pb(y);
						break;
					}
				}
				for (auto x:p1) {
					assert(sp[v].count(x));
					sp[v].erase(x);
					p0.pb(x);
				}
			}
			for (auto x:p0) sp[v].insert(x);
			for (auto y:p0) merge(x,y,E[i][0]);
		}
		f[u]=v;
		for (auto x:sp[u]) sp[v].insert(x);
		for (auto &x:fp[u]) for (auto y:x.se) {
			fp[v][x.fi].pb(y);
		}
		sp[u].clear(); fp[u].clear();
		sz[v]+=sz[u];
		/*rep(i,1,n+1) if (find(i)==i) {
			for (auto x:sp[i]) {
				printf("sp %d %d\n",i,x);
				for (auto y:fp[i][x]) printf("fp %d %d %d\n",i,x,y);
			}
		}
		puts("------");*/
	}
	rep(i,1,n+1) {
		fs[i].clear();
		fs[i].insert(i);
		f[i]=i;
	}
	rep(i,0,m) ret[i]=-1;
	for (auto p:e2) {
		int u=p[1],v=p[2],w=p[0];
		u=find(u); v=find(v);
		if (SZ(fs[u])>SZ(fs[v])) swap(u,v);
		for (auto p:fs[u]) for (auto q:qr[p]) {
			if (fs[v].count(q.fi)) ret[q.se]=w;
		}
		for (auto p:fs[u]) fs[v].insert(p);
		fs[u].clear();
		f[u]=v;
	}
	rep(i,0,m) {
		assert(ret[i]!=-1);
		printf("%d%c",ret[i]," \n"[i==m-1]);
	}
}

int main() {
	//freopen("A.in","r",stdin);
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}