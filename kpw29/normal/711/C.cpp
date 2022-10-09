#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
typedef pair <double, int> PDI;

const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, K, a, b, c, k, d, g, Q, DL;

#define maxn 105
ll dp[maxn][maxn][maxn];
int ins[maxn];
int cost[maxn][maxn];

int main() {
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, n) cin>> ins[i];
	FOR(i, 1, n)
	  FOR(j, 1, m) cin >> cost[i][j];
	
	FOR(i, 1, m) 
	  FOR(j, 1, k) dp[0][j][i] = INF;
	
	FOR(i, 1, n)
	  FOR(l, 1, m) dp[i][0][l] = INF;
	  
	FOR(i, 1, n)
	  FOR(j, 1, k) {
		 FOR(l, 0, m) dp[i][j][l] = INF;
		 if (ins[i]) {
			 FOR(ost, 1, m)
			   if (ost == ins[i] && i > 1) dp[i][j][ost] = min(dp[i][j][ost], dp[i-1][j][ost]);
			   else dp[i][j][ins[i]] = min(dp[i][j][ins[i]], dp[i-1][j-1][ost]);
		 }
		 else {
			FOR(l, 1, m)
			  FOR(ost, 1, m)
			    if (ost == l && i > 1) dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][ost] + cost[i][l]);
			    else dp[i][j][l] = min(dp[i][j][l], dp[i-1][j-1][ost] + cost[i][l]);
		 }
	  }
	
	/*FOR(i, 1, n)
	  FOR(j, 1, k)
	    FOR(l, 1, m) cout << "DANE: " << i << ' ' << j << ' ' << l << ": " << dp[i][j][l] << endl;*/
	ll ans = INF;
	FOR(i ,1, m) ans = min(ans, dp[n][k][i]);
	if (ans == INF) OUT(-1);
	cout << ans;
}