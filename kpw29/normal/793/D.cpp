#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, a, b, k,c;
#define maxn 82
int koszt[2010][2010];
ll dp[maxn][maxn][maxn][2];

inline ll getDP(int a, int b, int kk, int bit) {
	if (a > b || b < 1 || a > n) return INF;
	return dp[a][b][kk][bit];
}

int main()
{
	boost;
	cin >> n >> k >> m;
	FOR(i, 1, n+1)
		FOR(j, 1, n+1) koszt[i][j] = inf;
		
	FOR(i, 1, n)
		FOR(j, 1, n)
			FOR(kk, 1, k)
				FOR(bit, 0, 1) dp[i][j][kk][bit] = INF;
				
	FOR(i, 1, m)
	{
		cin >> a >> b >> c;
		koszt[a][b] = min(koszt[a][b], c);
	}
	FOR(i, 1, n) koszt[n+1][i] = 0;
	
				
	FOR(i, 1, n) dp[i][i][1][0] = 0, dp[i][i][1][1] = 0;
	
	FOR(len, 2, n)
		FOR(a, 1, n-len+1)
		{
			int b = a + len - 1;
			dp[a][b][1][0] = 0; dp[a][b][1][1] = 0;
			FOR(kk, 2, k)
			{
				for (int i=a+1; i<=b; ++i) dp[a][b][kk][0] = min(dp[a][b][kk][0], min(getDP(a + 1, i, kk-1, 1) + koszt[a][i], getDP(i, b, kk-1, 0) + koszt[a][i]));
				for (int i=a; i<b; ++i) dp[a][b][kk][1] = min(dp[a][b][kk][1], min(getDP(a, i, kk-1, 1) + koszt[b][i], getDP(i, b-1, kk-1, 0) + koszt[b][i]));
			}
		}
	
	/*FOR(i, 1, n)
		FOR(j, 1, n)
			FOR(kk, 1, k)
				FOR(bit, 0, 1) cout << "i, j, kk, bit " << i << ' ' << j << ' ' << kk << ' ' << bit << ' ' << dp[i][j][kk][bit] << endl;*/
				
	ll inba = INF;
	FOR(i, 1, n) inba = min(inba, min(getDP(1, i, k, 1), getDP(i, n, k, 0)));
	if (inba > k * 1000) cout << -1;
	else cout << inba;
}