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

const int MX = 1000005, SIG = 26;
int n, q, a[MX], cn[MX], sig[MX][SIG], res[MX], pos[MX], dp[MX], ord = 1;

void dfs (int u, int mn, int act) {
	if (pos[u]) {
		res[pos[u]] = dp[u] = min(dp[u], mn + ord);
		ord++;
	}

	mn = min(mn, dp[u] - act);
	act += bool(pos[u]);

	for (int j = 0; j < SIG; j++)
		if (sig[u][j]) {
			int v = sig[u][j];
			dp[v] = dp[u] + 1;
			dfs(v, mn, act);
			act += cn[v];
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		char c;

		cin >> p >> c;
		sig[p][c - 'a'] = i;
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> a[i];
		pos[a[i]] = i;
		cn[a[i]] = 1;
	}

	for (int i = n; i; i--)
		for (int j = 0; j < SIG; j++)
			cn[i] += cn[sig[i][j]];

	dfs(0, 0, 0);

	for (int i = 1; i <= q; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}