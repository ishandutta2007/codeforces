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

const int MX = 200005;
int n, a[MX], res[MX];
vi adj[MX];

void bfs (int f) {
	queue<int> q;
	vi dis(n + 1, -1);

	for (int i = 1; i <= n; i++)
		if (a[i] % 2 == f) {
			q.push(i);
			dis[i] = 0;
		}

	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (dis[v] == -1) {
				q.push(v);
				dis[v] = dis[u] + 1;
			}
	}

	for (int i = 1; i <= n; i++)
		if (a[i] % 2 == 1 - f)
			res[i] = dis[i];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (i - a[i] >= 1)
			adj[i - a[i]].pb(i);
		
		if (i + a[i] <= n)
			adj[i + a[i]].pb(i);
	}

	bfs(0);
	bfs(1);

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}