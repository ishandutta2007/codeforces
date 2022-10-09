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
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 51;

int dp[51][51][51][51];
char tab[51][51];
int pref[maxn][maxn], n;

inline int getSum(int a, int b, int c, int d) {
	return pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1];
}

int licz_dp(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2) return 0;
	if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
	int value = max(x2-x1+1, y2-y1+1);
	if (getSum(x1, y1, x2, y2) == 0) value = 0;
	else if (x1 == x2 && y1 == y2) //1x1 case
	{
		if (tab[x1][y1] == '.') value = 0;
		else value = 1;
	}
	else
	{
		for (int i = x1; i < x2; ++i)
		{
			value = min(value, licz_dp(x1, y1, i, y2) + licz_dp(i+1, y1, x2, y2));
		}
		
		for (int i = y1; i < y2; ++i)
		{
			value = min(value, licz_dp(x1, y1, x2, i) + licz_dp(x1, i+1, x2, y2));
		}
	}
	
	
	dp[x1][y1][x2][y2] = value;
	return value;
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n)
		FOR(j, 1, n) cin >> tab[i][j];
	
	FOR(i, 1, n)
		FOR(j, 1, n) pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (tab[i][j] == '#');
	FOR(i, 0, 50)
		FOR(j, 0, 50)
			FOR(k, 0, 50)
				FOR(l, 0, 50) dp[i][j][k][l] = -1;

	cout << licz_dp(1, 1, n, n);
}