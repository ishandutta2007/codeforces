#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 5100;
int arr[maxn];

ll dp[2][3000][2][2];
inline int odl(int a, int b) //spraw zeby a < b
{
	if (a < b) return 0;
	return a - b + 1;
}
int n;
ll best[5010];
int main()
{
	boost;
	cin >> n;
	int k = (n + 1) / 2;
	FOR(i, 1, n) cin >> arr[i];
	arr[0] = -inf; arr[n + 1] = -inf;
	
	
	FOR(j, 0, k)
		FOR(a, 0, 1) FOR(b, 0, 1) dp[0][j][a][b] = INF;
	dp[0][0][0][0] = 0;
	
	FOR(i, 1, k + 1) best[i] = INF;
	FOR(i, 1, n)
	{
		FOR(j, 0, k) 
			FOR(a, 0, 1) FOR(b, 0, 1) 
				dp[i & 1][j][a][b] = INF;
		
		FOR(j, 0, k)
		{
			dp[i & 1][j][1][1] = INF;
			dp[i & 1][j][1][0] = dp[(i-1)&1][j][0][1] + odl(arr[i], arr[i-1]);
			
			dp[i & 1][j][0][0] = min(dp[(i-1)&1][j][1][0], dp[(i-1)&1][j][0][0]);
			ll op1 = INF;
			if (i >= 2 && j >= 1) op1 = dp[(i - 1) & 1][j - 1][1][0] + odl(min(arr[i - 1], arr[i - 2] - 1), arr[i]);
			if (j >= 1) op1 = min(op1, dp[(i - 1)&1][j - 1][0][0] + odl(arr[i - 1], arr[i]));
			dp[i & 1][j][0][1] = op1;
			
			//FOR(a, 0, 1)
				//FOR(b, 0, 1) if (a + b != 2) cout << i << ' ' << j << ' ' << a << ' ' << b << " : " << dp[i&1][j][a][b] << endl;
			if (i == n)
			{
				FOR(a, 0, 1)
				FOR(b, 0, 1) best[j] = min(best[j], dp[i & 1][j][a][b]);
			}
		}
	}
	
	for (int help = k; help >= 0; --help) best[help] = min(best[help], best[help + 1]);
	FOR(i, 1, k) cout << best[i] << ' ';
}