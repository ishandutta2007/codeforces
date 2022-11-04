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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, p[MX], res[MX], vis[MX];
vi c[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vi v;

			int u = i;
			do {
				v.pb(u);
				u = p[u];
				vis[u] = 1;
			} while (u != i);

			int m = v.size();

			if (m % 2) {
				vi w(m);

				forn (i, m)
					w[2 * i % m] = v[i];

				forn (i, m)
					res[w[i]] = w[(i + 1) % m];
			} else if (c[m].size()) {
				vi w(2 * m);

				forn (i, m)
					w[2 * i] = v[i];

				forn (i, c[m].size())
					w[2 * i + 1] = c[m][i];

				forn (i, 2 * m)
					res[w[i]] = w[(i + 1) % (2 * m)];

				c[v.size()].clear();
			} else {
				c[v.size()] = v;
			}
		}

	for (int i = 1; i <= n; i++)
		if (c[i].size()) {
			cout << -1 << endl;
			return 0;
		}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}