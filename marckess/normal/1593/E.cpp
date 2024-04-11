// Problem : E. Gardener and Tree
// Contest : Codeforces - Codeforces Round #748 (Div. 3)
// URL : https://codeforces.com/contest/1593/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 500005;
int n, k, d[MX], ex[MX];
vi adj[MX];

void main_() {
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		d[i] = 0;
		ex[i] = 1;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
		
		d[u]++;
		d[v]++;
	}
	
	vi q;
	
	for (int i = 1; i <= n; i++)
		if (d[i] <= 1)
			q.pb(i);
	
	int res = 0;
	forn (i, k) {
		vi nex;
		
		if (!q.size())
			break;
		
		for (int u : q) {
			if (!ex[u]) continue;
			ex[u] = 0;
			res++;
			
			for (int v : adj[u])
				if (ex[v]) {
					d[v]--;
					
					if (d[v] <= 1)
						nex.pb(v);
				}
		}
		
		q = nex;
	}
	
	cout << n - res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}