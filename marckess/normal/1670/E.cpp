// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = (1 << 17) + 5;
int n, cn, pp, nr[MX], er[MX];
vii adj[MX];

void dfs (int u, int p, int f) {
	for (ii &v : adj[u])
		if (v.fi != p) {
			int x = cn;
			int y = (1 << pp) + cn;
			cn++;
			
			if (f) {
				er[v.se] = y;
				nr[v.fi] = x;
			} else {
				er[v.se] = x;
				nr[v.fi] = y;
			}
			
			dfs(v.fi, u, f ^ 1);
		}
}

void main_() {
	cin >> pp;
	n = 1 << pp;
	
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forr (i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}
	
	cn = 1;
	nr[1] = 1 << pp;
	dfs(1, 1, 1);
	
	cout << 1 << endl;
	forr (i, 1, n) cout << nr[i] << " "; cout << endl;
	forr (i, 1, n - 1) cout << er[i] << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}