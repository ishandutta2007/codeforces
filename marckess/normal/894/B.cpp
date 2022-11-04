#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

ll pot (ll b, ll p, ll m) {
	ll res = 1;
	b %= m;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}
		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

ll n, m, M = 1e9+7, k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	if (n % 2 == m % 2) {
		cout << pot(pot(2, n-1, M), m-1, M) << endl;
	} else {
		if (k == -1)
			cout << 0 << endl;
		else
			cout << pot(pot(2, n-1, M), m-1, M) << endl;
	}

	return 0;
}