#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

int n, k, p, u, v, ml;
int acu[MX];
vi adj[MX];

void dfs (int u, int p, int l) {
	acu[l]++;
	ml = max(ml, l);

	for (int v : adj[u])
		if (v != p)
			dfs(v, u, l+1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> p;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (k == 0) {
		cout << 0 << endl;
		return 0;
	}

	dfs(1, 1, 0);

	ll cnt = min(k, acu[ml]), res = cnt, cost = 0, i = ml, j = ml-1, l = 0;

	while (i) {
		while (cnt < k && j && cost + i - j <= p) {
			l++;
			cnt++;
			cost += i - j;

			if (l == acu[j]) {
				l = 0;
				j--;
			}
		}

		res = max(res, cnt);

		if (i - 1 == j) {
			i--;
			cnt = min(k, acu[i]);
			cost = 0;
			j--;
			l = 0;
		} else {
			cnt -= acu[i];
			cost -= cnt;
			i--;
		}
	}

	cout << res << endl;

	return 0;
}