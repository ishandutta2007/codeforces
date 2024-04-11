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

const int N=201000;
int n,p,l[N],r[N],tot,sz[N],deg[N],rt;
VI s[N];
set<PII> hs;
void dfs(int u) {
	l[u]=tot++;
	hs.insert(mp(l[u],u));
	bool evenp=1;
	sz[u]=1;
	for (auto v:s[u]) {
		deg[v]=1;
		dfs(v);
		if (sz[v]) {
			deg[u]^=1;
			sz[u]+=sz[v];
			evenp&=(sz[v]&1);
		}
	}
	r[u]=tot;
	if (deg[u]==0&&evenp) {
		sz[u]=0;
		while (1) {
			auto it=hs.lower_bound(mp(l[u],-1));
			if (it==hs.end()||it->fi>r[u]) break;
			printf("%d\n",it->se);
			hs.erase(it);
		}
	}
}
int main() {
	scanf("%d",&n);
	if (n%2==0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	rep(i,1,n+1) {
		scanf("%d",&p);
		if (p==0) rt=i;
		s[p].pb(i);
	}
	dfs(rt);
	assert(hs.empty());	
}