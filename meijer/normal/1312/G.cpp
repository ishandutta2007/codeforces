#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 1e6+100;
int n, p[MX], k, a[MX];
bitset<MX> inS;
char c[MX];
vi chl[MX];
int sz[MX];
int dp[MX];

void dfsSz(int u=0) {
	sz[u] = inS[u];
	for(int v:chl[u]) dfsSz(v), sz[u]+=sz[v];
}
void dfs(int u=0, int up=-1, int depth=0, int skip=0) {
	if(inS[u]) {
		if(up == -1) dp[u] = min(depth, skip+1);
		else dp[u] = min(dp[up]+depth, dp[up]+skip+1);
		if(dp[u] == dp[up]+skip+1) skip = 0;
		for(int v:chl[u]) {
			dfs(v, u, 1, min(1, skip));
			skip += sz[v];
		}
	} else {
		for(int v:chl[u]) {
			dfs(v, up, depth+1, min(skip, depth+1));
			skip += sz[v];
		}
	}
}

void program() {
	cin>>n;
	RE1(i,n) cin>>p[i]>>c[i];
	cin>>k;
	RE(i,k) cin>>a[i];
	inS.reset();
	RE(i,k) inS[a[i]] = 1;
	RE1(i,n) chl[p[i]].pb(i);
	REI(i,0,n) sort(chl[i].begin(), chl[i].end(), [](int i, int j) {
		return c[i] < c[j];
	});
	dfsSz();
	dfs();
	RE(i,k) cout<<(i==0?"":" ")<<dp[a[i]]; cout<<endl;
}