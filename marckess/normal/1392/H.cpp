#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 4000005, mod = 998244353;
ll n, m, inv[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	inv[0] = inv[1] = 1;
	for (ll i = 2; i < MX; i++)
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;

	cin >> n >> m;

	ll P = 0, Q = 1, acu = 1;

	for (ll i = 0; i < n; i++) {
		ll c = acu * m % mod * inv[n - i + m] % mod;

		(P += c * (i + 1)) %= mod;
		(Q += m * inv[i + 1]) %= mod;

		(acu *= (n - i) * inv[n - i + m] % mod) %= mod;
	}

	(P += acu * (n + 1)) %= mod;

	cout << P * Q % mod << endl;
	
	return 0;
}