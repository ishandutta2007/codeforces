#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

vi adj[ maxn ];
int ds[ maxn ];

int root(int a){
	return ds[a] < 0 ? a : ds[a] = root( ds[a] );
}

bool join(int a, int b){
	a = root(a), b = root(b);
	if (a == b) return false;
	if (ds[a] < ds[b]) swap(a, b);
	ds[b] += ds[a];
	ds[a] = b;
	return true;
}

int64 diam[ maxn ];
vector<int64>  f[ maxn ];
vector<int64>  F[ maxn ];
vector<int64> FF[ maxn ];

int total;
int q[ maxn ]; // queue
int64 d[ maxn ]; // distance

int64 A[ maxn ];

void bfs(int u){
	total = 0;
	d[ u ] = 0;
	q[ total++ ] = u;
	for (int i = 0; i < total; ++i){
		int v = q[i];
		for (auto x : adj[v]){
			if (d[x] != -1) continue;
			d[x] = d[v] + 1;
			q[total++] = x;
		}
	}
}

void compute(int u){
	int I = u;
	// cout << "COMPUTE: " << I << endl;

	bfs(u);
	for (int i = 0; i < total; ++i){
		if (d[ q[i] ] > d[u]) 
			u = q[i];
		d[ q[i] ] = -1;
	}
	bfs(u);
	for (int i = 0; i < total; ++i){
		A[ q[i] ] = d[ q[i] ];
		if (d[ q[i] ] > d[u]){
			u = q[i];
			diam[I] = max( diam[I], d[u] );
		}
		d[ q[i] ] = -1;
	}

	// cout << "Diameter: " << diam[I] << endl;
	
	f[ I ] = vector<int64>( diam[ I ] + 1 );
	F[ I ] = vector<int64>( diam[ I ] + 1 );
	FF[ I ] = vector<int64>( diam[ I ] + 1 );

	bfs(u);
	for (int i = 0; i < total; ++i){
		A[ q[i] ] = max( A[ q[i] ], d[ q[i] ]);
		f[I][ A[ q[i] ] ]++;
	}
	F[I][ diam[I] ] = f[I][diam[I]];
	FF[I][diam[I]] = diam[I] * F[I][diam[I]];
	
	for (int i = diam[I] - 1; i >= 0; --i){
		F[I][i] = F[I][i + 1] + f[I][i];
		FF[I][i] = FF[I][i + 1] + i * f[I][i];
	}

	// for (int i = 0; i <= diam[I]; ++i)
	// 	cout << f[I][i] << " " << F[I][i] << " " << FF[I][i] << endl;
	// cout << endl;
}

map<pii,double> memo;

double _calc(int u, int v){
	if (diam[u] > diam[v])
		swap(u, v);

	int64 C = max( diam[u], diam[v] );
	
	int64 used = 0;
	int64 value = 0;

	for (int i = diam[u]; i >=0 && f[u][i]; --i){
		int x = C - i;
		if (x > diam[v]) break;

		used += f[u][i] * F[v][x];
		value += f[u][i] * (FF[v][x] + 1LL * (i + 1) * F[v][x]);
	}

	assert(used <= F[u][0] * F[v][0]);
	value += C * (F[u][0] * F[v][0] - used);

	return 1. * value / F[u][0] / F[v][0];
}

double calc(int u, int v){
	if (u > v) swap(u, v);
	pii cur(u, v);

	if (memo.find(cur) == memo.end())
		memo[ cur ] = _calc(u, v);

	return memo[ cur ];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, q;
	cin >> n >> m >> q;

	memset(ds, -1, sizeof ds);
	memset(d, -1, sizeof d);

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		join(u, v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i){
		if (i == root(i))
			compute(i);
	}

	while (q--){
		int u, v; cin >> u >> v;

		u = root(u), v = root(v);
		
		if (u == v){
			cout << -1 << endl;
			continue;
		}

		cout.precision(10);
		cout << fixed << calc(u, v) << endl;
	}

	return 0;
}