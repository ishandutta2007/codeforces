#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, m, ds[100005], rk[100005] = {0}, tam[100005], q[100005], a, b;
ll v[100005], res = 0, act;
vvi adj;
bitset<100005> exi;

int parent (int a) {
	return a == ds[a] ? a : ds[a] = parent(ds[a]);
}

void joint (int a, int b) {
	a = parent(a), b = parent(b);

	if (a == b || !exi[b] || !exi[a])
		return;

	res += act * tam[a] * tam[b];

	if (rk[a] > rk[b]) {
		ds[b] = a;
		tam[a] += tam[b];
	} else {
		ds[a] = b;
		tam[b] += tam[a];
		if (rk[a] == rk[b])
			rk[b]++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	adj = vvi(n+1);

	for (int i = 1; i <= n; i++)
		cin >> v[i]; 
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	iota(q+1, q+n+1, 1);
	sort(q+1, q+n+1, [&] (int x, int y) {
		return v[x] > v[y];
	});
	iota(ds+1, ds+n+1, 1);
	fill(tam, tam+n+1, 1);

	for (int i = 1; i <= n; i++) {
		int u = q[i];
		act = v[u];
		exi[u] = 1;

		for (int x : adj[u])
			joint(u, x);
	}

	cout << fixed << setprecision(5) << ld(res * 2) / (n * ld(n-1)) << endl;

	return 0;
}