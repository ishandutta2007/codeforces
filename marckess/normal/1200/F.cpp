#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 1005, mod = 2520;
int n, k[MX], m[MX], e[MX][11], q, x, y, w;
int mp[MX][mod+5], vis[MX][mod+5];
set<int> st;
 
void dfs (int v, int x, int tov, int tox) {
	st.insert(v);
	if (v == tov && x == tox) return;
 
	x = MOD(x + k[v], mod);
	v = e[v][x % m[v]];
	dfs(v, x, tov, tox);
}
 
int dp(int v, int x) {
	if (mp[v][x] != -1) return mp[v][x];
	
	int sx = MOD(x + k[v], mod);
	int sv = e[v][sx % m[v]];
 
	if (vis[sv][sx] == w) {
		st.clear();
		dfs(sv, sx, v, x);
		return mp[v][x] = st.size();
	}
 
	vis[sv][sx] = w;
	return mp[v][x] = dp(sv, sx);
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) cin >> k[i+1];
	forn(i, n) {
		cin >> m[i+1];
		forn(j, m[i+1])
			cin >> e[i+1][j];
	}
 
	memset(mp, -1, sizeof(mp));
	cin >> q;
	for (w = 1; w <= q; w++) {
		cin >> x >> y;
		vis[x][MOD(y, mod)] = w;
		cout << dp(x, MOD(y, mod)) << endl;
	}
 
	return 0;
}