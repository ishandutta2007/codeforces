#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = (ll)1e18 + 3;
const int R = (1 << 16);
PII dr[2 * R + 5];

inline void treeInsert(int gdzie, int pocz, int kon, int x, int y, int ile)
{
	if (x <= pocz && y >= kon)
	{
		dr[gdzie].e1 += ile;
		dr[gdzie].e2 += ile;
		return;
	}
	int sr = (pocz + kon) >> 1;
	if (x <= sr) treeInsert((gdzie << 1) | 0, pocz, sr, x, y, ile);
	if (y > sr) treeInsert((gdzie << 1) | 1, sr+1, kon, x, y, ile);
	dr[gdzie].e1 = max(dr[gdzie << 1 | 0].e1, dr[gdzie << 1 | 1].e1) + dr[gdzie].e2;
}

inline int treeQuery(int gdzie, int pocz, int kon, int x, int y)
{
	if (x <= pocz && y >= kon)
	{
		return dr[gdzie].e1;
	}
	int sr = (pocz + kon) >> 1;
	int rm = 0;
	if (x <= sr) rm = max(rm, treeQuery((gdzie << 1) | 0, pocz, sr, x, y));
	if (y > sr) rm = max(rm, treeQuery((gdzie << 1) | 1, sr+1, kon, x, y));
	dr[gdzie].e1 = max(dr[gdzie << 1 | 0].e1, dr[gdzie << 1 | 1].e1) + dr[gdzie].e2;
	return rm;
}

#define maxn 35100
int dp[maxn][51], tab[maxn], n, k, LAST[maxn];

int main()
{
	boost;
	cin >> n >> k;
	FOR(i, 1, n) cin >> tab[i];
	FOR(j, 1, k)
	{
		FOR(i, 0, 2 * R - 1) dr[i].e1 = dr[i].e2 = 0;
		FOR(i, 1, n) treeInsert(1, 1, R, i, i, dp[i-1][j-1]), LAST[tab[i]] = 0;
		FOR(i, 1, n)
		{
			treeInsert(1, 1, R, LAST[tab[i]] + 1, i, 1);
			dp[i][j] = treeQuery(1, 1, R, 1, i);
			LAST[tab[i]] = i;
		}
	}
	
	cout << dp[n][k];
}