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

const int MX = 2e6, mod = 998244353;
int n;
ll fac[MX], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fac[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n;

	ll res = 0;
	for (int i = 1; i < n; i++)
		res += inv[i];
	res %= mod;

	cout << MOD(fac[n] * (n - res), mod) << endl;  

	return 0;
}