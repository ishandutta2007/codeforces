#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m, k, CC = 0, T;
#define maxn 1010

int dp[maxn][maxn], t[maxn][maxn], a, b, c ,d;
const int R = 1024;
int rmq[10][10][R + 2][R + 2];
inline int LOG(int x) {
	return 31 - __builtin_clz(x);
}
inline int query(int a, int b, int c, int d) {
	int L1 = LOG(c - a + 1), L2 = LOG(d - b + 1);
	int ans = max(max(rmq[L1][L2][a][b], rmq[L1][L2][a][d - (1 << L2) + 1]), 
	max(rmq[L1][L2][c - (1 << L1) + 1][b], rmq[L1][L2][c - (1 << L1) + 1][d - (1 << L2) + 1]));
	return ans;
}

int main() {
	boost;
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	FOR(i, 1, n)
	  FOR(j, 1, m) cin >> t[i][j];

	FOR(i, 1, n)
	  FOR(j, 1, m) {
	    if (!t[i][j]) dp[i][j] = 0;
	    else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
	}

	FOR(L1, 0, 9)
	  FOR(L2, 0, 9)
	    for (int i=1; i+(1 << (L1)) - 1 <= n; ++i)
	      for (int j=1; j+(1 << L2) - 1 <= m; ++j) {
			  if (L1 == 0 && L2 == 0) rmq[0][0][i][j] = dp[i][j];
			  else if (L1 == 0) rmq[L1][L2][i][j] = max(rmq[L1][L2 - 1][i][j], rmq[L1][L2 - 1][i][j + (1 << (L2 - 1))]);
			  else if (L2 == 0) rmq[L1][L2][i][j] = max(rmq[L1 - 1][L2][i][j], rmq[L1 - 1][L2][i + (1 << (L1 - 1))][j]);
			  else rmq[L1][L2][i][j] = max(max(rmq[L1 - 1][L2 - 1][i][j], rmq[L1 - 1][L2 - 1][i][j + (1 << (L2 - 1))]),
			  max(rmq[L1 - 1][L2 - 1][i + (1 << (L1 - 1))][j], rmq[L1 - 1][L2 - 1][i + (1 << (L1 - 1))][j + (1 << (L2 - 1))]));
		  }
	
	int zap;
	cin >> zap;
	while (zap--) {
		cin >> a >> b >> c >> d;
		int x = 0, y = min(d-b+1, c-a+1);
		
		while (x < y) {
			int sr = ((x + y) >> 1) + 1;
			if (query(a+sr-1, b+sr-1, c, d) < sr) y = --sr;
			else x = sr;
		}
		cout << x << "\n";
	}
}