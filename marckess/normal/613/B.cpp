#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e5+5;
int n;
ll mx, cf, cm, m, a[MX], b[MX], q[MX];
ll res = 0, ri = 0, rj, acu[MX], s = 0;

bool esPos (ll k, int lim) {
	ll i = 0, j = lim, rep = 18;

	while (rep--) {
		ll m = (i+j)/2;
		if (a[m] >= k) j = m;
		else i = m;
	}

	j--;
	if (j >= 0) return k * (j + 1) - acu[j] + s <= m;
	return 1;
}

ll binBus (ll lim) {
	ll i = 0, j = mx, rep = 30;

	while (rep--) {
		ll m = (i+j)/2;
		if (esPos(m, lim)) i = m;
		else j = m;
	}

	if (esPos(j, lim)) return j;
	return i;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> mx >> cf >> cm >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return a[i] < a[j];
	});
	sort(a, a+n);

	for (int i = 0; i < n; i++) {
		acu[i] = a[i];
		if (i) acu[i] += acu[i-1];
	}

	int j = n;
	rj = n;
	while (j >= 0) {
		if (j < n) s += mx - a[j];

		if (s <= m) {
			ll x = binBus(j), d;

			if (x == mx) d = cm * x + n * cf;
			else d = cm * x + (n - j) * cf;

			if (d > res) {
				res = d;
				ri = x;
				rj = j;
			}
		}

		j--;
	}

	for (int i = 0; i < n; i++) {
		if (i >= rj) b[q[i]] = mx;
		else b[q[i]] = max(a[i], ri);
	}

	cout << res << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}