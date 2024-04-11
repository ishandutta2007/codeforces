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

const int MX = 200005;
int n, k, s, t, acu[MX], res = 2e9+5;
int g[MX], c[MX], v[MX];

bool esPos (int mit) {
	int x = -1, ti = 0;
	for (int i = 0; i < n; i++)
		if (c[i] <= mit)
			x = max(x, v[i]);

	if (x == -1) return 0;

	for (int i = 0; i < k; i++) {
		if (2 * g[i] <= x)  {
			ti += g[i];
			continue;
		}
		if (g[i] > x) return 0;

		int y = x - g[i];
		ti += y + 2 * (g[i] - y);
	}

	return ti <= t;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++)
		cin >> c[i] >> v[i];
	for (int i = 0; i < k; i++)
		cin >> g[i];
	g[k++] = s;
	sort(g, g+k);

	for (int i = k-1; i; i--) g[i] -= g[i-1];

	int i = 0, j = 1e9+5, rep = 32;
	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (j == 1e9+5) cout << -1 << endl;
	else cout << j << endl;

	return 0;
}