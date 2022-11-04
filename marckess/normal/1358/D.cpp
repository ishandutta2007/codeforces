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

const int MX = 1000005;
ll n, a[MX], b[MX], res, x;

ll tri (ll n) {
	return n * (n + 1) / 2;
}

ll mej (ll a, ll x) {
	ll res = 0;
	if (a <= x) {
		res = tri(a);
	} else {
		ll d = a - x; 
		res = tri(a) - tri(d);
	}
	return res;
}

void solve () {
	forn (i, n) {
		b[i] = tri(a[i]);
		res = max(res, mej(a[i], x));
	}

	int i = 0, j = 0;
	ll s = 0, p = 0;

	while (i < n) {
		while (j < n && s + a[j] <= x) {
			s += a[j];
			p += b[j];
			j++;
		}

		if (i < j) {
			ll fal = x - s;
			ll x = 0, y = 0;

			if (i) {
				x = mej(a[i - 1], fal);
				ll d = fal - a[i - 1];

				if (d > 0 && j < n)
					x += tri(min(d, a[j]));
			}

			if (j < n) {
				y = tri(min(fal, a[j]));
				ll d = fal - a[j];

				if (d > 0 && i)
					y += mej(a[i - 1], d);
			}

			res = max(res, p + max(x, y));
		}

		s -= a[i];
		p -= b[i];
		i++;

		if (i > j) {
			j = i;
			s = p = 0;
		}
	}

	i = n - 1, j = n - 1;
	while (j >= 0) {
		while (i >= 0 && s + a[i] <= x) {
			s += a[i];
			p += b[i];
			i--;
		}

		if (i < j) {
			ll fal = x - s;
			ll x = 0, y = 0;

			if (i >= 0) {
				x = mej(a[i], fal);
				ll d = fal - a[i];

				if (d > 0 && j + 1 < n)
					x += tri(min(d, a[j + 1]));
			}

			if (j + 1 < n) {
				y = tri(min(fal, a[j + 1]));
				ll d = fal - a[j + 1];

				if (d > 0 && i >= 0)
					y += mej(a[i], d);
			}

			res = max(res, p + max(x, y));
		}

		s -= a[j];
		p -= b[j];
		j--;

		if (i > j) {
			i = j;
			s = p = 0;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x;
	forn (i, n) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	n *= 2;

	solve();

	cout << res << endl;

	return 0;
}