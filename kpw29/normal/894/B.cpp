#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;

inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a)%mod;
		a = (a * a)%mod;
		b >>= 1;
	}
	return res;
}
int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	if (k == -1 && (n % 2 != m % 2)) OUT(0);
	n--; m--;
	n %= (mod - 1);
	m %= (mod - 1);
	ll a = potmod(2, n * m) % mod;
	OUT(a);
}