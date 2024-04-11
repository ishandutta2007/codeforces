#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 30;
int n, m, x, y, w, a[MX], b[LMX+2];
bitset<MX> bs;
vii adj[MX];

void add (int v) {
	for (int j = LMX; j >= 0; j--)
		if (v & (1 << j))
			if (!b[j]) {
				b[j] = v;
				return;
			} else {
				v ^= b[j];
			}
}

void dfs (int u) {
	bs[u] = 1;

	for (ii &v : adj[u]) {
		if (bs[v.fi]) {
			add(a[v.fi] ^ a[u] ^ v.se);
		} else {
			a[v.fi] = a[u] ^ v.se;
			dfs(v.fi); 
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	dfs(1);

	for (int j = LMX; j >= 0; j--)
		if ((a[n] & (1 << j)) && b[j])
			a[n] ^= b[j];

	cout << a[n] << endl;

	return 0;
}