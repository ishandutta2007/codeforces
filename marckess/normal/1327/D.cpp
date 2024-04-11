#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], c[MX], vis[MX], res;

void solve () {
	cin >> n;
	forn (i, n) cin >> p[i + 1];
	forn (i, n) cin >> c[i + 1];

	res = n;
	fill(vis + 1, vis + n + 1, 0);

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int u = i;
			vi v;

			do {
				v.pb(c[u]);
				vis[u] = 1;
				u = p[u];
			} while (u != i);

			for (int d = 1; d <= v.size(); d++)
				if (v.size() % d == 0)
					for (int j = 0; j < d; j++) {
						int f = 1;

						for (int k = j + d; k < v.size(); k += d)
							f &= v[j] == v[k];
						
						if (f)
							res = min(res, d);
					}
		}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}