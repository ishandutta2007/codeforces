#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100100;
const int MAGIC = 345;

int n, m, q;
ll a[N];
vector<int> imps;
int id[N];
ll ans[MAGIC], lz[MAGIC];
int f[N][MAGIC];
vector<int> sub[N];
vector<int> where[N];

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= m; ++i) {
		int sz;
		cin >> sz;
		sub[i].resize(sz);
		for (int &u : sub[i]) {
			cin >> u;
			where[u].push_back(i);
		}
		if (sz > MAGIC) {
			imps.push_back(i);
			id[i] = imps.size();
			for (int u : sub[i]) {
				ans[id[i]] += a[u];
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int u : where[i]) {
			if (id[u]) {
				for (int v : where[i]) {
					++f[v][id[u]];
				}
			}
		}
	}
	
	while (q--) {
		char op;
		cin >> op;
		if (op == '+') {
			int k,  x;
			cin >> k >> x;
			if (id[k]) {
				lz[id[k]] += x;
			} else {
				for (int u : sub[k]) {
					a[u] += x;
				}
				for (int i = 1; i <= imps.size(); ++i) {
					ans[i] += x * f[k][i];
				}
			}
		} else {
			int k;
			cin >> k;
			ll res = 0;
			if (id[k]) {
				res = ans[id[k]];
			} else {
				for (int u : sub[k]) {
					res += a[u];
				}
			}
			for (int i = 1; i <= imps.size(); ++i) {
				res += lz[i] * f[k][i];
			}
			
			cout << res << '\n';
		}
	}
}