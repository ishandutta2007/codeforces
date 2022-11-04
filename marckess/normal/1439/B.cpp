#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k, d[MX], ex[MX];
unordered_set<int> adj[MX];

bool clique (vi &v) {
	forn (i, v.size())
		forn (j, i)
			if (!adj[v[i]].count(v[j]))
				return 0;
	return 1;
}

vi go (int k) {
	if (k * (k - 1) / 2 > m) return {};
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		d[i] = adj[i].size();
		
		if (d[i] < k)
			q.push(i);
		
		ex[i] = 1;
	}
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		ex[u] = 0;
		
		if (d[u] == k - 1) {
			vi res = {u};
			
			for (int v : adj[u])
				if (ex[v])
					res.pb(v);
					
			if (clique(res))
				return res;
		}
		
		for (int v : adj[u])
			if (ex[v]) {
				d[v]--;
				
				if (d[v] == k - 1)
					q.push(v);
			}
	}
	
	vi res;
	for (int i = 1; i <= n; i++)
		if (ex[i])
			res.pb(i);
	
	return res;
}

void solve () {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		ex[i] = 0;
		adj[i].clear();
	}
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	vi v = go(k);
	
	if (v.size() > k) {
		cout << 1 << " " << v.size() << endl;
		
		for (int x : v)
			cout << x << " ";
		cout << endl;
		
		return;
	}
	
	if (v.size() == k) {
		cout << 2 << endl;
		
		for (int x : v)
			cout << x << " ";
		cout << endl;
		
		return;
	}
	
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}