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

const int N=201000;

typedef unordered_map<int,int> mcnt;


int n,_,f[N],a[N],deg[N],q[N],dep[N],ans[N];
vector<pair<ll,int>> Q[N];
mcnt st[N],*nd[N];
VI v[N],qv[N];

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

void merge(mcnt* &a,mcnt *&b) {
	if (a->size()<b->size()) swap(a,b);
	for (auto p:*b) (*a)[p.fi]+=p.se;
	b->clear();
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) f[i]=i;
	rep(i,1,n+1) {
		scanf("%d",a+i);
		f[find(i)]=find(a[i]);
		++deg[a[i]];
	}
	scanf("%d",&_);
	rep(i,0,_) {
		ll m;int y;
		scanf("%lld%d",&m,&y);
		Q[y].pb(mp(m,i));
	}
	rep(i,1,n+1) v[find(i)].pb(i);
	rep(x,1,n+1) if (!v[x].empty()) {
		auto vv=v[x];
		int t=0;
		for (auto u:vv) if (deg[u]==0) {
			q[t++]=u;
		}
		rep(i,0,t) {
			int u=q[i];
			--deg[a[u]];
			if (deg[a[u]]==0) q[t++]=a[u];
		}
		int ps=0;
		for (auto u:vv) if (deg[u]) {
			f[u]=u;
			ps=u;
		}
		per(i,0,t) {
			int u=q[i];
			dep[u]=dep[a[u]]+1;
			f[u]=f[a[u]];
		}
		int qs=ps;
		int m=0;
		VI cyc;
		while (1) {
			m++;
			cyc.pb(qs);
			qs=a[qs];
			if (qs==ps) break;
		}
		rep(i,0,m) qv[i].clear();
		for (auto u:vv) {
			st[u][dep[u]]=1;
			nd[u]=st+u;
		}
		rep(i,0,t) {
			int u=q[i];
			for (auto pr:Q[u]) {
				int pd=dep[u]+pr.fi;
				if (nd[u]->count(pd)) {
					ans[pr.se]=(*nd[u])[pd];
				}
			}
			merge(nd[a[u]],nd[u]);
		}
		rep(i,0,m) {
			int u=cyc[i];
			for (auto dd:*nd[u]) {
				// a=dd.fi p=i
				rep(j,0,dd.se) qv[(dd.fi-i+m)%m].pb(dd.fi);
			}
		}
		rep(i,0,m) sort(all(qv[i]));
		rep(i,0,m) {
			int u=cyc[i];
			for (auto pr:Q[u]) {
				ll z=(pr.fi-i+m)%m;
				ans[pr.se]=upper_bound(all(qv[z]),pr.fi)-qv[z].begin();
			}
		}
	}
	rep(i,0,_) printf("%d\n",ans[i]);
}