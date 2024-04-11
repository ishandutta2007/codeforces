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

const int MX = 200005, mod = 998244353;
int n, m;
vi a, b, c, d;

void solve () {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);

	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;

	c.resize(n);
	for (int i = n - 1; i >= 0; i--) {
		c[i] = a[i];
		if (i + 1 < n) c[i] = min(c[i], c[i + 1]);
	}

	int j = 0;
	for (int i = 0; i < n; i++)
		if (j < m && c[i] == b[j])
			j++;

	if (j < m || c[0] != b[0]) {
		cout << 0 << endl;
		return;
	}

	ll res = 1;
	for (int i = 1; i < m; i++) {
		auto it = equal_range(all(c), b[i]);
		(res *= it.se - it.fi) %= mod;
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}