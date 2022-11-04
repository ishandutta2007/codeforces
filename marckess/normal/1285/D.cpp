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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], sig[30 * MX][2], sz, mn[30 * MX];

void insert (int x, int i) {
	int u = 0;
	while (i >= 0) {
		int to = bool(x & (1 << i));
		if (!sig[u][to]) sig[u][to] = ++sz;
		u = sig[u][to];
		i--; 
	}
}

void dfs (int u, int i) {
	if (!u && i < 29) return;
	dfs(sig[u][0], i-1);
	dfs(sig[u][1], i-1);
	
	if (sig[u][0] && sig[u][1]) {
		mn[u] = min(mn[sig[u][0]], mn[sig[u][1]]) + (1 << i);
	} else {
		mn[u] = max(mn[sig[u][0]], mn[sig[u][1]]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		insert(a[i], 29);
	}

	dfs(0, 29);
	cout << mn[0] << endl;

	return 0;
}