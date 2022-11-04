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

const int MX = 200005;
int n, a[MX], d[MX], ex[MX];
vi adj[MX];
multiset<int> mst[MX];

void main_() {
	cin >> n;
	
	forn (i, n)
		cin >> a[i];
		
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	ll res = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	
	forn (i, n) {
		if (adj[i].size() == 1) {
			pq.emplace(a[i], i);
			mst[i].insert(0);
		}
		ex[i] = 1;
		d[i] = adj[i].size();
	}
	
	while (pq.size()) {
		int u = pq.top().se;
		pq.pop();
		
		ex[u] = 0;
		
		int in = *mst[u].rbegin();
		mst[u].erase(mst[u].find(in));
		
		res += max(0, a[u] - in);
		in = max(in, a[u]);
		
		if (!d[u]) {
			res += max(0, a[u] - *mst[u].rbegin());
		}
		
		for (int v : adj[u])
			if (ex[v]) {
				mst[v].insert(in);
				d[v]--;
				
				if (d[v] == 1)
					pq.emplace(a[v], v);
			}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}