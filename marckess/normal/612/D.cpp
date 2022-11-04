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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 3000005;
int n, k, a[MX], l[MX], r[MX];
vi c;
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	forn (i, n) {
		cin >> l[i] >> r[i];
		c.pb(2 * l[i]);
		c.pb(2 * r[i]);
		c.pb(2 * r[i] + 1);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	forn (i, n) {
		l[i] = lower_bound(all(c), 2 * l[i]) - c.begin();
		r[i] = lower_bound(all(c), 2 * r[i]) - c.begin();

		a[l[i]]++;
		a[r[i] + 1]--;
	}

	forn (i, c.size()) {
		if (i) a[i] += a[i - 1];

		if (a[i] >= k) {
			if (res.size() && res.back().se + 1 == c[i]) {
				res.back().se = c[i + 1] - 1;
			} else {
				res.emplace_back(c[i], c[i + 1] - 1);
			}
		}
	}

	cout << res.size() << endl;
	for (ii &x : res)
		cout << x.fi / 2 << " " << x.se / 2 << endl;

	return 0;
}