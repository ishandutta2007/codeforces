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

const int MX = 2005;
int n, m, x[MX], y[MX], c[MX], k[MX], u[MX * MX], v[MX * MX], q[MX * MX];
int p[MX], mn[MX], cen;
ll w[MX * MX], res;
vii par;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		res += c[i];
		p[i] = i;
		mn[i] = c[i];
	}

	for (int i = 1; i <= n; i++)
		cin >> k[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++) {
			u[m] = i;
			v[m] = j;
			w[m] = ll(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			m++;
		}

	iota(q, q + m, 0);
	sort(q, q + m, [&] (int i, int j) {
		return w[i] < w[j];
	});

	cen = n;
	for (int kk = 0; kk < m; kk++) {
		int i = q[kk];
		int x = parent(u[i]);
		int y = parent(v[i]);

		if (x == y)
			continue;

		if (w[i] < max(mn[x], mn[y])) {
			res -= max(mn[x], mn[y]);
			res += w[i];
			par.emplace_back(u[i], v[i]);
			cen--;

			if (mn[x] < mn[y]) {
				p[y] = x;
			} else {
				p[x] = y;
			}
		}
	}

	cout << res << endl;

	cout << cen << endl;
	for (int i = 1; i <= n; i++)
		if (parent(i) == i)
			cout << i << " ";
	cout << endl;

	cout << par.size() << endl;
	for (auto p : par)
		cout << p.fi << " " << p.se << endl;

	return 0;
}