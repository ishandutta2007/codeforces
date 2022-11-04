#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
ll n, k[MX], cn[MX], in[MX];
vi a[MX];
ll res;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void solve () {
	cin >> n;

	for (int i = 1; i < MX; i++)
		in[i] = pot(i, mod - 2);

	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			int x;
			cin >> x;
			a[i].pb(x);
			cn[x]++;
		}
	}

	ll w = in[n] * in[n] % mod;
	for (int i = 0; i < n; i++) {
		ll q = w * in[k[i]] % mod;
		for (int x : a[i]) {
			res += cn[x] * q % mod;
		}
		res %= mod;
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	t = 1;
	while (t--)
		solve();

	return 0;
}