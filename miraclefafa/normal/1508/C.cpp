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

const int N=201000;
array<int,3> E[N];
set<int> unvis;
int n,m,neg[N],f[N],root,cnt;
ll ans;
vector<PII> e[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int i) {
	for (auto x:e[i]) {
		neg[x.fi]=i;
	}
	VI vv;
	for (auto x:unvis) {
		if (neg[x]==i) continue;
		vv.pb(x);
		f[x]=root;
	}
	for (auto x:vv) unvis.erase(x);
	for (auto x:vv) dfs(x);
}

int main() {
	scanf("%d%d",&n,&m);
	int s=0;
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i]={w,u,v};
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
		s^=w;
	}
	for (int i=1;i<=n;i++) unvis.insert(i);
	for (int i=1;i<=n;i++) if (unvis.count(i)) {
		cnt++;
		root=i;
		f[i]=i;
		unvis.erase(i);
		dfs(i);
	}
	ll negx=1ll*n*(n-1)/2-m;
	if (negx==n-cnt) {
		sort(E,E+m);
		rep(i,1,n+1) f[i]=i;
		vector<array<int,3>> imp;
		set<PII> st;
		rep(i,0,m) {
			int u=E[i][1],v=E[i][2];
			st.insert(mp(u,v));
			st.insert(mp(v,u));
			if (find(u)!=find(v)) {
				imp.push_back(E[i]);
				f[find(u)]=find(v);
			}
		}
		vector<array<int,3>> ext;
		rep(i,1,n+1) rep(j,i+1,n+1) if (!st.count(mp(i,j))) {
			ext.pb({0,i,j});
		}
		ll ans=1ll<<60;
		rep(i,0,SZ(ext)) {
			auto q=ext;
			q[i][0]=s;
			for (auto x:imp) q.push_back(x);
			sort(all(q));
			rep(i,1,n+1) f[i]=i;
			ll tmp=0;
			for (auto ee:q) {
				int u=ee[1],v=ee[2];
				if (find(u)!=find(v)) {
					f[find(u)]=find(v);
					tmp+=ee[0];
				}
			}
			ans=min(ans,tmp);
		}
		printf("%lld\n",ans);
		// senlin
	} else {
		sort(E,E+m);
		rep(i,0,m) {
			int u=E[i][1],v=E[i][2];
			if (find(u)!=find(v)) {
				ans+=E[i][0];
				f[find(u)]=find(v);
			}
		}
		printf("%lld\n",ans);
	}
}