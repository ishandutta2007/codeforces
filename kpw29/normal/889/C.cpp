#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false); cin.tie(0)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
int tab[maxn], n, m, k;
ll fac[maxn], invfac[maxn];

ll A[maxn], F[maxn];
inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a)%mod;
		a = (a * a)%mod;
		b >>= 1;
	}
	return res;
}

inline ll binom(ll n, ll k) {
	if (k == 0) return 1;
	return fac[n] * invfac[k] % mod * invfac[n - k]%mod;
}

inline ll getF(int p) {
	return A[p-1] * invfac[p-1] % mod;
}

int main()
{
	cin >> n >> k;
	fac[0] = 1;
	for (int i=1; i<=n; ++i) fac[i] = fac[i-1] * i % mod;
	invfac[n] = potmod(fac[n], mod - 2);
	for (int i=n-1; i>=0; --i) invfac[i] = invfac[i + 1] * (i + 1)%mod;
	A[0] = 1; F[0] = 1;
	if (k > n - 2) OUT(0);
	F[1] = 1; A[1] = 1;

	ll tmp = getF(1);
	for (int i=2; i<=n; ++i) {
		if (i - k > 0) tmp -= getF(i - k), tmp += mod;
		tmp += getF(i);
		tmp %= mod;
		A[i] = tmp * fac[i-1];
		A[i] %= mod;
	}
	
	for (int i=n; i<=n; ++i) {
		for (int p = 1; p <= i; ++p) {
			ll res = A[p - 1] % mod;
			res *= binom(i - 1, p - 1); res %= mod;
			res *= fac[i - p]; res %= mod;
			F[i] += res;
		}
		F[i] %= mod;
	}
	cout << (fac[n] - F[n] + mod)%mod;
}