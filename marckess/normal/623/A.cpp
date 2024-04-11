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

const int MX = 505;
int n, m, mat[MX][MX];
char res[MX];
vi adj[MX];

void no () {
	cout << "No" << endl;
	exit(0);
}

void dfs (int u) {
	for (int v : adj[u]) {
		if (!res[v]) {
			res[v] = res[u] == 'a' ? 'c' : 'a';
			dfs(v);
		} else if (res[u] == res[v]) {
			no();
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && !mat[i][j]) {
				adj[i].pb(j);
			}

	for (int i = 1; i <= n; i++)
		if (!adj[i].size())
			res[i] = 'b';

	for (int i = 1; i <= n; i++)
		if (!res[i]) {
			res[i] = 'a';
			dfs(i);
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && mat[i][j] != (abs(res[i] - res[j]) <= 1))
				no();

	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
		cout << res[i];
	cout << endl;

	return 0;
}