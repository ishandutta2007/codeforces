#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, a, b;
vvi adj;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	adj = vvi(n, vi(n, 1e9));
	for (int i = 0; i < n; i++) {
		cin >> a;
		adj[i][a-1] = 1;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	ll res = 1;
	for (int i = 0; i < n; i++) {
		if (adj[i][i] == 1e9) {
			cout << -1 << endl;
			return 0;
		}

		if (adj[i][i] % 2 == 0)
			adj[i][i] /= 2;
		res = res * adj[i][i] / gcd(res, adj[i][i]);
	}

	cout << res << endl;

	return 0;
}