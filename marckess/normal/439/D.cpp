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

const int MX = 100005;
int n, m, a[MX], b[MX];
ll za[MX], zb[MX], res = 1e18;
set<int> c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c.insert(a[i]);
	}

	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		c.insert(b[i]);
	}

	sort(a+1, a+n+1);
	sort(b+1, b+m+1);

	for (int i = 1; i <= n; i++) za[i] = za[i-1] + a[i];
	for (int i = 1; i <= m; i++) zb[i] = zb[i-1] + b[i];

	for (int x : c) {
		int k = upper_bound(a+1, a+n+1, x) - a - 1;
		int l = lower_bound(b+1, b+m+1, x) - b;

		res = min(res, x * ll(k - (m - l + 1)) + (zb[m] - zb[l-1]) - za[k]);
	}

	cout << res << endl;

	return 0;
}