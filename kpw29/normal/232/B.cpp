#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 110
ll binom[maxn][maxn], n, m, k;
ll ile[maxn];

int dp[105][10010];
inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0){
		if (b & 1) res = (res * a) %mod;
		a = (a * a)%mod;
		b /= 2;
	}
	return res;
}
ll pm[105][105];

int main() {
	cin >> n >> m >> k;
	binom[0][0] = 1;
	FOR(i, 1, n) binom[i][i] = binom[i][0] = 1;
	FOR(i, 1, n)
	FOR(j, 1, i-1) binom[i][j] = (binom[i-1][j-1] + binom[i-1][j])%mod;
	FOR(i, 1, n) {
		ll mn = (m / n);
		ll w = m - (n * mn);
		if (w >= i) ++mn;
		ile[i] = mn;
	}
	
	FOR(i, 1, n)
	   FOR(kk, 0, n) pm[i][kk] = potmod(binom[n][kk], ile[i]);
	    
	
	
	dp[0][0] = 1;
	FOR(i, 1, n) {
		for (int up=0; up<=k; ++up)
		  for (int il=0; il<=n; ++il)
		    if (up - il >= 0) {
				ll w = ((ll)dp[i-1][up-il] * pm[i][il] % mod);
				dp[i][up] += w;
				while (dp[i][up] >= mod) dp[i][up] -= mod;
			}
	}
	
	cout << dp[n][k] % mod;
}