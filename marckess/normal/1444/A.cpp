#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

ll p, q;

void solve () {
	ll res = 1;
	cin >> p >> q;
	swap(p, q);
	ll a = p;
	
	for (ll i = 2; i * i <= a; i++)
		if (a % i == 0) {
			ll x = q;
			while (x % i == 0) {
				if (x % p != 0) res = max(res, x);
				x /= i;
			}
			if (x % p != 0) res = max(res, x);
			while (a % i == 0) a /= i;
		}
	
	if (a > 1) {
		ll x = q;
		while (x % a == 0) {
			if (x % p != 0) res = max(res, x);
			x /= a;
		}
		if (x % p != 0) res = max(res, x);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}