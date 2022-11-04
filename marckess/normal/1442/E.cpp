#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], d[MX], res;
vi adj[MX];
queue<int> q[3];

void go (int f) {
	for (int i = 1; i <= n; i++) {
		d[i] = adj[i].size();
		
		if (d[i] < 2)
			q[a[i]].push(i);
	}
	
	int r = 0;
	
	while (q[0].size() + q[1].size() + q[2].size()) {
		while (q[0].size() + q[f].size()) {
			int u;
			
			if (q[0].size()) u = q[0].front(), q[0].pop();
			else u = q[f].front(), q[f].pop();
			
			for (int v : adj[u]) {
				d[v]--;
				
				if (d[v] == 1)
					q[a[v]].push(v);
			}
		}
		
		r++;
		f ^= 3;
	}
	
	res = min(res, r);
}

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[i].clear();
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	res = n;
	go(1);
	go(2);
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}