#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 2010
char s[maxn];
ll dp[maxn][maxn];
int tab[maxn], n, k;
inline void moduluj(ll &x) {
	while (x >= mod) x -= mod;
}
ll prefSum[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	FOR(i, 1, n) tab[i] = s[i] - 'a' + 1;
	
	dp[0][0] = 1;
	prefSum[0] = 1;
	FOR(i, 1, n)
	{
		FOR(j, 0, k) dp[i][j] += prefSum[j] * (tab[i] - 1) % mod, moduluj(dp[i][j]);
		
		int noweSlowa = 0;
		for (int lt = i - 1; lt >= 0; --lt)
		{
			noweSlowa += n - (i - 1);
			for (int j=0; j<=k-noweSlowa; ++j)
				dp[i][j + noweSlowa] += dp[lt][j] * (26 - tab[i]) % mod, moduluj(dp[i][j + noweSlowa]);
		}
		
		FOR(j, 0, k) prefSum[j] += dp[i][j];
	}
	
	ll res = 0;
	FOR(j, 0, n) res += dp[j][k];
	cout << res % mod;
}