#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;

int64 tri(int64 v){
	return v * (v - 1) / 2;
}

int ds[ maxn ], deg[maxn], ok[ maxn ];

int root(int a){
	return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
	a = root(a), b = root(b);
	if (a == b) return false;
	if (ds[a] < ds[b]) swap(a, b);
	ds[b] += ds[a];
	ds[a] = b;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int c = n;

	memset(ds, -1, sizeof ds);

	int64 answer = 0;
	int64 prev = 0;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		c -= join(u, v);

		ok[u] = ok[v] = 1;

		if (u == v){
			answer += m - ++prev;
		}
		else{
			deg[u]++;
			deg[v]++;
		}
	}

	for (int i = 1; i <= n; ++i)
		if (ok[i] == 0) --c;

	if (c > 1){
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		answer += tri( deg[i] );

	cout << answer << endl;

	return 0;
}