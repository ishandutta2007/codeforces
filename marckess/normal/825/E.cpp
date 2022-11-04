#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n, m, u, v;
vvi adj;
vi out, eti;
set<int> out0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	adj = vvi(n+1), out = vi(n+1), eti = vi(n+1);

	while (m--) {
		cin >> u >> v;
		adj[v].push_back(u);
		out[u]++;
	}

	//Inicialmente out-degre 0
	for (int i = 1; i <= n; i++)
		if (!out[i])
			out0.insert(i);

	//Etiquetar
	for (int i = n; i > 0; i--) {
		auto it = out0.end();
		--it;
		u = *it;
		out0.erase (it);
		eti[u] = i;

		for (int v : adj[u]) {
			out[v]--;
			if (!out[v])
				out0.insert(v);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << eti[i] << " ";
	cout << endl;

	return 0;
}