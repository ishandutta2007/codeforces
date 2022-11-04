#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], f = 0, cn = 0, mn = 1e9;
bitset<MX> vis;

vi g[MX];

void dfs (int i, int c) {
	if (vis[i]) return;
	g[c].pb(i);
	vis[i] = 1;
	dfs(a[i], c);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			dfs(i, cn);
			mn = min(mn, (int)g[cn].size());
			f |= g[cn].size() > 2 && g[cn].size() % 2;
			cn++;
		}

	if (mn == 1) {
		cout << "YES" << endl;
		for (int i = 0; i < cn; i++)
			if (g[i].size() == 1) {
				for (int j = 1; j <= n; j++)
					if (g[i][0] != j)
						cout << g[i][0] << " " << j << endl;
				break;
			}
		return 0;
	}

	if (f || mn > 2) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for (int i = 0; i < cn; i++)
		if (g[i].size() == 2) {
			cout << g[i][0] << " " << g[i][1] << endl;
			for (int j = 0; j < cn; j++)
				if (i != j)
					for (int k = 0; k < g[j].size(); k++)
						cout << g[i][k%2] << " " << g[j][k] << endl;
			break;
		}

	return 0;
}