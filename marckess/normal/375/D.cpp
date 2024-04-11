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

const int M = 100005;
int n, m, c[M], ca[M], q[M], l[M], r[M], k[M], fi[M], blo[M], res[M], a, b, x, y, tam, co = 1, acu = 0;
vvi adj;
vi in(M), cub(M), ft(M);

void dfs (int u) {
	in[u] = fi[u] = co;
	ca[co++] = c[u];

	for (int v : adj[u]) {
		if (in[v] == 0) {
			dfs(v);
			fi[u] = max(fi[u], fi[v]);
		}
	}
}

bool comp (int a, int b) {
	if (blo[a] != blo[b])
		return blo[a] < blo[b];
	return r[a] < r[b];
}

void suma (int i) {
	ft[++cub[i]]++;
}

void resta (int i) {
	ft[cub[i]--]--;
}

int main () {	
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	tam = sqrt(n);
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	adj = vvi(n+2);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);

	for (int i = 0; i < m; i++) {
		cin >> x >> k[i];
		l[i] = in[x];
		r[i] = fi[x];
		q[i] = i;
		blo[i] = l[i] / tam;
	}

	sort (q, q+m, comp);

	a = 1, b = 0;
	for (int i = 0; i < m; i++) {
		x = l[q[i]], y = r[q[i]];
		
		while (a < x) 
			resta(ca[a++]);
		while (a > x)
			suma(ca[--a]);
		while (b < y)
			suma(ca[++b]);
		while (b > y)
			resta(ca[b--]);

		res[q[i]] = ft[k[q[i]]]; 
	}

	for (int i = 0; i < m; i++)
		cout << res[i] << endl;

	return 0;
}