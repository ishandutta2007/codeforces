#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

vector<ll> c;

void pre () {
	ll p[20];
	p[0] = 1;
	for (int i = 1; i < 19; i++)
		p[i] = 10 * p[i-1];

	for (int i = 0; i < 19; i++) {
	for (int a = 1; a < 10; a++) {
		c.pb(a * p[i]);
	}
	}

	for (int i = 0; i < 18; i++) {
	for (int a = 1; a < 10; a++) {
		for (int j = i+1; j < 18; j++) {
		for (int b = 1; b < 10; b++) {
			c.pb(a * p[i] + b * p[j]);
		}
		}
	}
	}

	for (int i = 0; i < 18; i++) {
	for (int a = 1; a < 10; a++) {
		for (int j = i+1; j < 18; j++) {
		for (int b = 1; b < 10; b++) {
			for (int k = j+1; k < 18; k++) {
			for (int d = 1; d < 10; d++) {
				c.pb(a * p[i] + b * p[j] + d * p[k]);
			}
			}
		}
		}
	}
	}

	sort(ALL(c));
}

int t;
ll l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();
	
	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << upper_bound(ALL(c), r) - lower_bound(ALL(c), l) << endl;
	}

	return 0;
}