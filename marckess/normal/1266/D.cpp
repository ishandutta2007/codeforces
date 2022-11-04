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
int n, m, cn;
ll s[MX];
vii adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int u, v, d;
		cin >> u >> v >> d;
		s[u] += d;
		s[v] -= d;
	}


	int i = 1, j = 1;
	while (i <= n) {
		while (i <= n && s[i] <= 0)
			i++;
		while (j <= n && s[j] >= 0)
			j++;

		if (i > n) break;
		assert(j <= n);

		ll d = min(s[i], -s[j]);
		adj[i].emplace_back(j, d);
		s[i] -= d;
		s[j] += d;
		cn++;
	}

	cout << cn << endl;
	for (int i = 1; i <= n; i++)
		for (ii &r : adj[i])
			cout << i << " " << r.fi << " " << r.se << endl;

	return 0;
}