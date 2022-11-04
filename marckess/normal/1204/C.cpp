#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, p[MX], adj[105][105], k, v[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '1') adj[i][j] = 1;
			else adj[i][j] = 1e9 * (i != j);
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> p[i];

	for (int i = 0; i < m;) {
		v[k++] = p[i];
		int mx = 1;
		for (int j = 1; j <= n && (i + j) < m; j++)
			if (adj[p[i]][p[i+j]] == j)
				mx = j;
		i += mx;
	}

	cout << k << endl;
	forn(i, k) cout << v[i] << " ";
	cout << endl;

	return 0;
}