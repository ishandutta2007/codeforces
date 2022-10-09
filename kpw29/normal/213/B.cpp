#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 150
const int N = 125;

ll dp[maxn][maxn], wyn[maxn], newdp[maxn], pref[maxn];
int n, m, k, a, b, c, T;
int lit[30], l2[30], ile[30];

int main() {
	FOR(i, 0, N) dp[1][i] = 1;
	dp[0][0] = 1;
	FOR(i, 1, N)
	{
		dp[i][0] = 1;
		pref[0] = 1;
		FOR(j, 1, N) 
		{
			pref[j] = (pref[j-1] + dp[i-1][j]);
			while (pref[j] >= mod) pref[j] -= mod;
		}
		FOR(j, 1, N) dp[i][j] = pref[j];
	}
	
	cin >> n;
	int suma = 0;
	FOR(i, 0, 9)
	{
		cin >> ile[i];
		suma += ile[i];
	}
	if (suma > n) OUT(0);
	FOR(i, ile[1], n) wyn[i] = 1;

	FOR(i, 2, 9) {
		FOR(j, 0, n) newdp[j] = 0;
		FOR(j, 0, n)
		  FOR(kk, 0, j)
		  {
			  int diff = j - kk;
			  if (diff >= ile[i]) newdp[j] = (newdp[j] + dp[kk + 1][diff] * wyn[kk])%mod;
		  }
		FOR(j, 0, n) wyn[j] = newdp[j];
	}

	FOR(j, 0, n) newdp[j] = 0;
	FOR(j, 0, n)
	  FOR(kk, 0, j)
	  {
		  int diff = j - kk;
		  if (diff >= ile[0]) newdp[j] = (newdp[j] + dp[kk][diff] * wyn[kk])%mod;
	  }
	ll ww = 0;
	FOR(i, suma, n) ww = (ww + newdp[i])%mod;
	if (suma == 0) cout << (ww-1+mod)%mod;
	else cout << ww;
}