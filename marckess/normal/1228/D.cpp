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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, cn[4], res[MX];
set<int> adj[MX];

void no () {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	int mx = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		if (!res[i]) {
			if (j > 3) no();
			res[i] = j;
			cn[j]++;
			mx = j;

			for (int k = 1; k <= n; k++)
				if (i != k && !adj[i].count(k)) {
					if (res[k] && res[k] != res[i]) no();
					res[k] = j;
					cn[j]++;
				}

			j++;
		}
	}

	if (mx < 3) no();

	for (int i = 1; i <= n; i++) {
		for (int j : adj[i])
			if (res[i] == res[j])
				no();
		if (adj[i].size() != n - cn[res[i]])
			no();
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}