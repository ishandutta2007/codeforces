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

const int MX = 5005;
int n, m[15], a[15][5005], b[15][5005], vis[(1 << 15) + 5];
ll sum[15];
ii res[15];
ll tar = 0;
map<ll, int> mp;

bool dfs (int u) {
	if (__builtin_popcount(u) == n)
		return 1;

	if (vis[u])
		return 0;
	vis[u] = 1;

	for (int i = 0; i < n; i++)
		if (!(u & (1 << i))) {
			for (int j = 0; j < m[i]; j++)
				if (a[i][j] != -1 && !(u & b[i][j]) && dfs(u | b[i][j])) {
					int u = i;
					int val = a[i][j];

					while (1) {
						ll ned = tar - (sum[u] - val);
						int v = mp[ned];

						res[v] = {ned, u};
						u = v;
						val = ned;

						if (v == i) break;
					}

					return 1;
				}

			break;
		}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(b, -1, sizeof(b));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];

		for (int j = 0; j < m[i]; j++) {
			cin >> a[i][j];

			mp[a[i][j]] = i;
			tar += a[i][j];
			sum[i] += a[i][j];
		}
	}

	if (tar % n) {
		cout << "no" << endl;
		return 0;
	}
	tar /= n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i]; j++) {
			int mk = 0;
			int u = i;
			int val = a[i][j];

			while (1) {
				ll ned = tar - (sum[u] - val);

				if (mp.count(ned)) {
					int v = mp[ned];

					if ((v == i && ned != a[i][j]) || (mk & (1 << v))) {
						mk = -1;
						break;
					}

					mk |= (1 << v);
					u = v;
					val = ned;

					if (v == i) break;
				} else {
					mk = -1;
					break;
				}
			}

			if (mk != -1) {
				b[i][j] = mk;
			}
		}
	}

	if (dfs(0)) {
		cout << "YeS" << endl;
		for (int i = 0; i < n; i++)
			cout << res[i].fi << " " << res[i].se + 1 << endl;
	} else {
		cout << "nO" << endl; 
	}

	return 0;
}