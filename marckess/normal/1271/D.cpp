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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 5005;
int n, m, k;
int a[MX], b[MX], c[MX], d[MX], vis[MX];
vi adj[MX];
priority_queue<int> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] > k) {
			cout << -1 << endl;
			return 0;
		}
		k += b[i];
		d[i] = k - a[i+1];
	}

	for (int i = n - 1; i >= 1; i--)
		d[i] = min(d[i], d[i+1]);

	for (int i = n; i >= 1; i--)
		d[i] -= d[i-1];

	int res = 0;
	for (int i = n; i >= 1; i--) {
		if (!vis[i]) {
			vis[i] = 1;
			pq.push(c[i]);
		}

		for (int v : adj[i])
			if (!vis[v]) {
				vis[v] = 1;
				pq.push(c[v]);
			}

		while (d[i]-- && pq.size()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << endl;

	return 0;
}