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

const int MX = 1000005;
int n, a[MX], b[MX];
ll res = 0, m;
vl v, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m += a[i];
	}

	if (m < 2) {
		cout << -1 << endl;
		return 0;
	}

	for (ll i = 2; i * i <= m; i++)
		if (m % i == 0) {
			d.pb(i);
			while (m % i == 0)
				m /= i;
		}

	if (m > 1)
		d.pb(m);

	ll res = 1e18;
	for (ll x : d) {
		ll p = 0;
		forn(i, n) b[i] = a[i] % x;

		for (int i = 0; i < n;) {
			int j = i, m = i;
			ll s = 0;

			if (!b[i]) {i++; continue;}

			while (m < n && 2 * s < x) {
				s += b[m];
				m++;
			}
			m--;

			s = 0;
			while (j < n && s < x) {
				ll d = min(x - s, 1ll * b[j]);
				b[j] -= d;
				p += abs(j - m) * d;
				j++;
				s += d;
			}

			i = j - 1;
		}

		res = min(res, p);
	}

	cout << res << endl;

	return 0;
}