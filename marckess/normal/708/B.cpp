#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll tri (ll n) {
	ll res = 1;

	while (res * (res - 1) / 2 < n)
		res++;

	if (res * (res - 1) / 2 == n)
		return res;

	return -1;
}

ll a00, a10, a01, a11;
ll n;
vector<ll> v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a00 >> a01 >> a10 >> a11;

	ll x = tri(a00);
	ll y = tri(a11);
	n = x + y;

	if (x == -1 || y == -1) {
		cout << "Impossible" << endl;
		return 0;
	}

	if (!a00 || !a11) {
		if (!a01 && !a10) {
			if (!a00 && !a11) cout << 1;
			if (a00) while (x--) cout << '0';
			if (a11) while (y--) cout << '1';
			cout << endl;

			return 0;
		}

		if (!a00 && !a11) {
			if (a01 == 1 && a10 == 0) cout << "01";
			else if (a01 == 0 && a10 == 1) cout << "10";
			else cout << "Impossible";
			cout << endl;
			return 0;
		}

		if (!a00) {
			if (a10 + a01 != y) {
				cout << "Impossible" << endl;
			} else {
				for (int i = 0; i < a10; i++)
					cout << '1';
				cout << '0';
				for (int i = 0; i < a01; i++)
					cout << '1';
				cout << endl;
			}
			return 0;
		}

		if (!a11) {
			if (a10 + a01 != x) {
				cout << "Impossible" << endl;
			} else {
				for (int i = 0; i < a01; i++)
					cout << '0';
				cout << '1';
				for (int i = 0; i < a10; i++)
					cout << '0';
				cout << endl;
			}
			return 0;
		}

		cout << "Impossible" << endl;

		return 0;
	}

	if (n * (n - 1) / 2 - a00 - a11 != a01 + a10) {
		cout << "Impossible" << endl;
		return 0;
	}

	ll ned = a01;
	for (int i = 0; i < y; i++) {
		ll d = min(x, ned);
		v.push_back(d);
		ned -= d;
	}

	sort(ALL(v));

	ll z = 0;
	for (int i = 0; i < v.size(); i++)
		z += (x - v[i]);

	if (a10 != z) {
		cout << "Impossible" << endl;
		return 0;
	}

	if (ned || (v.size() && v[0] < 0)) {
		cout << "Impossible" << endl;
		return 0;
	}

	int acu = 0;
	for (int x : v) {
		while (acu < x) {
			cout << '0';
			acu++;
		}
		cout << '1';
	}

	while (acu < x) {
		cout << '0';
		acu ++;
	}
	cout << endl;

	return 0;
}