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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, k, a[MX], d1[MX], dn[MX], res, q[MX];
int mx = 0;
multiset<int> st;
vi adj[MX];

void bfs (int s, int d[]) {
	queue<int> q;
	q.push(s);
	d[s] = 0;

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	memset(d1, -1, sizeof(d1));
	memset(dn, -1, sizeof(dn));

	cin >> n >> m >> k;
	
	for (int i = 0; i < k; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs(1, d1);
	bfs(n, dn);

	sort(a, a+k, [&] (int i, int j) {
		return d1[i] - dn[i] < d1[j] - dn[j];
	});

	for (int i = 0; i < k; i++)
		st.insert(dn[a[i]]);

	for (int i = 0; i + 1 < k; i++) {
		int u = a[i];
		st.erase(st.find(dn[u]));
		mx = max(mx, d1[u] + *st.rbegin() + 1);
	}

	cout << min(mx, d1[n]) << endl;

	return 0;
}