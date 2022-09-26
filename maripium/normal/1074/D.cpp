#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int q;
map<int,int> par;
map<int,int> f;
int last = 0;

int anc(int u) { 
	if (!par.count(u)) return u;
	int p = par[u];
	par[u] = anc(p);
	f[u] ^= f[p];
	return par[u];
}

void join(int u,int v,int x) {
	int pu = anc(u), pv = anc(v);
	if (pu == pv) return;
	par[pv] = pu;
	f[pv] = f[u] ^ f[v] ^ x;
}

int get(int u,int v) {
	int pu = anc(u), pv = anc(v);
	if (pu ^ pv) return -1;
	return f[u] ^ f[v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int l, r, x; cin >> l >> r >> x;
			l ^= last, r ^= last, x ^= last;
			if (l > r) swap(l, r);
			join(l - 1, r, x);
		}
		else {
			int l, r; cin >> l >> r;
			l ^= last, r ^= last;
			if (l > r) swap(l, r);
			last = get(l - 1, r);
			cout << last << '\n';
			if (last == -1) last = 1;
		}
	}
}