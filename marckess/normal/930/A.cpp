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
int n, p[MX], lvl[MX], res = 0;
vi adj[MX];

void dfs (int u, int l) {
	lvl[l]++;
	for (int v : adj[u])
		dfs(v, l+1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}

	dfs(1, 0);

	for (int i = 0; i < MX; i++)
		res += lvl[i] % 2;
	cout << res << endl;

	return 0;
}