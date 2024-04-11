#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 200005, mod = 998244353;
int n;
ll acu = 1, res = 0, f[MX], d[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	f[0] = 1;
	for (ll i = 1; i < MX; i++)
		f[i] = f[i-1] * i % mod;

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		d[u]++;
		d[v]++;
	}

	for (int i = 1; i <= n; i++)
		(acu *= f[d[i] - 1] * d[i] % mod) %= mod;

	for (int i = 1; i <= n; i++) {
		(res += acu * pot(f[d[i] - 1] * d[i] % mod, mod - 2) % mod * f[d[i]] % mod) %= mod;
	}

	cout << res << endl;
 
	return 0;
}