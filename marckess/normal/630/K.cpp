#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	ll res = 0;

	for (int i = 0; i < (1 << 11); i++) {
		if (i & 3) continue;
		ll f = 1, d = 1;

		for (int j = 2; j <= 10; j++)
			if (i & (1 << j)) {
				d = d * j / gcd(d, j);
				f *= -1;
			}

		res += n / d * f;
	}

	cout << res << endl;

	return 0;
}