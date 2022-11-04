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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, k, p[MX], dis[MX];
vi adj[MX];
vi go[MX];
queue<int> q;

void bfs (int s) {
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;
	q.push(s);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		go[a].pb(b);
		adj[b].pb(a);
	}

	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> p[i];

	bfs(p[k]);

	int mn = 0, mx = 0;
	for (int i = 1; i < k; i++) {
		if (dis[p[i]] - 1 == dis[p[i + 1]]) {
			int cn = 0;
			for (int v : go[p[i]])
				if (dis[p[i]] - 1 == dis[v])
					cn++;
			if (cn > 1)
				mx++;
		} else {
			mx++, mn++;
		}
	}

	cout << mn << " " << mx << endl;

	return 0;
}