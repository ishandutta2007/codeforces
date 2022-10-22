#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
int T, k, a, b, t, n;
vii adj[MX], chl[MX];
ll dp[MX];
int sz[MX];
int root=0;

int dfs(int v, int p) {
	sz[v] = 1;
	for(ii u:adj[v])
		if(u.fi != p)
			sz[v] += dfs(u.fi, v), chl[v].pb(u);
	return sz[v];
}
ll getDP(int v) {
	if(dp[v] == -1) {
		dp[v] = 0;
		for(ii u:chl[v]) {
			if(sz[u.fi] % 2) {
				dp[v] += getDP(u.fi);
				dp[v] += u.se;
			} else {
				dp[v] += getDP(u.fi);
			}
		}
	}
	return dp[v];
}
ll getAns2(int v) {
	ll ans=0;
	for(ii u:chl[v]) {
		ll mult = min(sz[root]-sz[u.fi], sz[u.fi]);
		ans += mult*u.se;
		ans += getAns2(u.fi);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>k; n=2*k;
		RE(i,n) adj[i].clear(), chl[i].clear();
		RE(i,n-1)
			cin>>a>>b>>t, a--, b--, adj[a].pb({b,t}), adj[b].pb({a,t});
		RE(i,n) if(adj[i].size() == 1) root = i;
		dfs(root,-1);
		RE(i,n) dp[i]=-1;
		ll ans = getDP(root);
		cout<<ans<<" "<<getAns2(root)<<endl;
	}
}