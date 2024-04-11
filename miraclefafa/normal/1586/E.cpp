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

const int N=301000;
int n,m,q,f[N],deg[N],vis[N],pt[N];
VI e[N];
vector<VI> ans;
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		if (find(u)==find(v)) continue;
		f[find(u)]=find(v);
		e[u].pb(v);
		e[v].pb(u);
	}
	scanf("%d",&q);
	rep(_,0,q) {
		int a,b;
		scanf("%d%d",&a,&b);
		deg[a]^=1; deg[b]^=1;
		rep(i,1,n+1) vis[i]=0;
		function<bool(int,int)> dfs=[&](int u,int dep) {
			pt[dep]=u;
			vis[u]=1;
			if (u==b) {
				ans.pb(VI(pt,pt+dep+1));
				return true;
			}
			for (auto v:e[u]) {
				if (!vis[v]) {
					if (dfs(v,dep+1)) return true;
				}
			}
			return false;
		};
		assert(dfs(a,0));
	}
	int s=0;
	rep(i,1,n+1) if (deg[i]) s+=1;
	if (s) {
		puts("NO");
		printf("%d\n",s/2);
		return 0;
	}
	puts("YES");
	rep(i,0,q) {
		printf("%d\n",SZ(ans[i]));
		for (auto x:ans[i]) printf("%d ",x); puts("");
	}
}