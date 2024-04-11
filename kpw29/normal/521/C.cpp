#include <bits/stdc++.h>
#include <string>
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
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100003

int n, m, a, b, c, d, T, k;

ll fac[maxn], pot10[maxn], pref[maxn];
 string s;
inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a)%mod;
		a = (a * a)%mod;
		b >>= 1;
	}
	return res;
}
inline ll INV(ll x) {
	return potmod(x, mod - 2)%mod;
}
inline ll dwumian(int n, int k) {
	if (k > n) return 0;
	ll gora = fac[n];
	ll dol = INV(fac[k]) * INV(fac[n-k]);
	return dol % mod * gora % mod;
}

int main()
{
	boost;
	cin >> n >> k;
	fac[0] = 1; pot10[0] = 1;
	FOR(i, 1, n) 
	{
		fac[i] = (fac[i-1] * i)%mod;
		pot10[i] = (pot10[i-1] * 10)%mod;
	}
	cin >> s;
	pref[0] = s[0] - '0';
	FOR(i, 1, n-1) pref[i] = pref[i-1] + s[i] - '0';
	ll wyn = 0;

	FOR(i, 0, n-1) 
	{
		ll w = pot10[n-1-i] * dwumian(i, k) % mod;
		w = w * (s[i] - '0')% mod;
		wyn = (wyn + w)%mod;
	}
	FOR(i, 0, n-2)
	{
		ll w = pot10[i] * dwumian(n - i - 2, k - 1) % mod;
		w = (w * pref[n-i-2])%mod;
		wyn = (wyn + w)%mod;
	}
	cout << wyn;
		
}