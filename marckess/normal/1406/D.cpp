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

const int MX = 100005;
ll n, a[MX], q, l, r, x, b[MX], s;

ll ceil (ll a, ll b) {
	if (a * b > 0) {
		a = abs(a);
		b = abs(b);
		return (a + b - 1) / b;
	}

	return a / b;
}

ll f (ll s) {
	return ceil(a[1] + s, 2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) b[i - 1] = a[i] - a[i - 1];
		s += max(0ll, b[i - 1]);
	}

	cout << f(s) << endl;

	cin >> q;
	while (q--) {
		cin >> l >> r >> x;

		if (l > 1) {
			s -= max(0ll, b[l - 1]);
			b[l - 1] += x;
			s += max(0ll, b[l - 1]);
		} else {
			a[l] += x;
		}

		if (r < n) {
			s -= max(0ll, b[r]);
			b[r] -= x;
			s += max(0ll, b[r]);
		}

		cout << f(s) << endl;
	}

	return 0;
}