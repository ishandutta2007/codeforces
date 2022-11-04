#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, a[4005], b[4005];
	bitset<4005> adj[4005];

	cin >> n >> m;

	vi tam(n+1);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];

		adj[a[i]][b[i]] = 1;
		adj[b[i]][a[i]] = 1;
		tam[a[i]]++;
		tam[b[i]]++;
	}

	int res = 1e9;
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			vi v = {a[i], b[i], a[j], b[j]};
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());

			if (v.size() != 3)
				continue;

			if (adj[v[0]][v[1]] && adj[v[1]][v[2]] && adj[v[2]][v[0]]) {
				res = min(res, tam[v[0]] + tam[v[1]] + tam[v[2]] - 6);
			}
		}
	}

	if (res == 1e9)
		cout << -1 << endl;
	else
		cout << res << endl;

	return 0;
}