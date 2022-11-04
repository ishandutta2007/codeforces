#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, in[MX];
vii adj[MX];

bool esPos (int m) {
	queue<int> q;
	memset(in, 0, sizeof(in));

	for (int i = 1; i <= n; i++)
		for (ii &v : adj[i])
			if (v.se <= m)
				in[v.fi]++;

	for (int i = 1; i <= n; i++)
		if (!in[i])
			q.push(i);

	while (q.size()) {
		if (q.size() > 1) return 0;
		
		int u = q.front();
		q.pop();

		for (ii &v : adj[u])
			if (v.se <= m) {
				in[v.fi]--;
				if (!in[v.fi])
					q.push(v.fi);
			}
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i);
	}

	int i = 1, j = m + 1, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (j == m + 1) cout << -1 << endl;
	else cout << j << endl;
	
	return 0;
}