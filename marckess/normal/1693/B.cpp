// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], l[MX], r[MX];
ll res;
vi adj[MX];

ll dfs (int u) {
	ll acu = 0;
	for (int v : adj[u])
		acu += dfs(v);
	
	acu = min(acu, 1ll * r[u]);
	if (acu < l[u]) {
		res++;
		acu = r[u];
	}
	
	return acu;
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	forr (i, 1, n) {
		cin >> l[i] >> r[i];
	}
	
	res = 0;
	dfs(1);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}