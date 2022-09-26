#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q, l;
long long a[N];
int par[N], len[N];
int res = 0;

int anc(int u) { return par[u] == u ? u : par[u] = anc(par[u]); }
void join(int u,int v) {
	u = anc(u), v = anc(v);
	if (u == v) return;
	par[v] = u;
	res--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q >> l;
	for (int i = 1; i <= n; ++i) par[i] = i;
	for (int i = 1; i <= n; ++i) cin >> a[i], len[i] = a[i] > l, res += len[i];
	for (int i = 2; i <= n; ++i) {
		if (len[i] && len[i - 1]) join(i - 1, i);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			cout << res << '\n';
		}
		else {
			int p, d; cin >> p >> d;
			if (a[p] <= l && a[p] + d > l) {
				res++;
				len[p] = 1;
				if (len[p - 1]) join(p - 1, p);
				if (len[p + 1]) join(p, p + 1);
			}
			a[p] += d;
		}
	}
}