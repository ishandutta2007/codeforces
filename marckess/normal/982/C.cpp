#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, u, v, res = 0;
vi adj[MX];

int dfs (int u, int p) {
	int x = 1;

	for (int v : adj[u]) {
		if (v == p)
			continue;
		x += dfs(v, u);
	}

	if (x & 1) {
		return 1;
	} else {
		res++;
		return 0;
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    if (dfs(1, 1))
    	cout << -1 << endl;
    else
    	cout << res - 1 << endl;

    return 0;
}