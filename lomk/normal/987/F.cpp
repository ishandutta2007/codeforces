/*input
2 3
1 2 3


*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 4200005
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

struct dsu {
	int par[N]; int cnt = 0;
	dsu() {
		memset(par, -1, sizeof(par));
	}
	void init(int x) {
		if (par[x] != -1) return;
		par[x] = x; cnt++;
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void uni(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			par[x] = y;
			cnt--;
		}
	}
} d;

int m, n;
vector<int> a;
int mark[N];
bool rmark[N];

int revMask(int x) {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		int b = bit(x, i) ^ 1;
		ret |= (b << i);
	}
	return ret;
}

void print(int mask) {
	for (int i = m - 1; i >= 0; i--) cout << bit(mask, i);
	cout << sp << mask;
	cout << endl;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	memset(mark, -1, sizeof(mark));
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		a.push_back(t);
		int rv = revMask(t);
		rmark[t] = true;
		mark[rv] = t;
		d.init(t);
	}
	for (int mask = (1 << (m)) - 1; mask >= 0; mask--) {
		if (mark[mask] == -1) continue;
		for (int j = 0; j < m; j++) {
			if (bit(mask, j)) {
				if (rmark[mask ^ (1 << j)]) {
					d.uni(mask ^ (1 << j), mark[mask]);
				}
				if (mark[mask ^ (1 << j)] == -1) {
					mark[mask ^ (1 << j)] = mark[mask];
				}
				else {
					if (rmark[mask ^ (1 << j)])
						d.uni(mark[mask ^ (1 << j)], mark[mask]);
				}
			}
		}
		if (rmark[mask]) {
			d.uni(mask, mark[mask]);
		}
	}
	cout << d.cnt << endl;
}