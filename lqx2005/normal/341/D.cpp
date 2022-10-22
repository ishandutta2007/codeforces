#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1000 + 10;
int n, m;
struct twoFenwick {
	ull t[N][N];
	void add(int x, int y, ull v) {
		for(int i = x; i <= n; i += i & (-i)) {
			for(int j = y; j <= n; j += j & (-j)) {
				t[i][j] ^= v;
			}
		}
		return;
	}
	ull ask(int x, int y) {
		ull res = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			for(int j = y; j > 0; j -= j & (-j)) {
				res ^= t[i][j];
			}
		}
		return res;
	}
}tree[2][2];

void add(int x, int y, ull w) {
	tree[x & 1][y & 1].add(x, y, w);
}

ull ask(int x, int y) {
	return tree[x & 1][y & 1].ask(x, y);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int opt, xa, ya, xb, yb;
		scanf("%d%d%d%d%d", &opt, &xa, &ya, &xb, &yb);
		if(opt == 2) {
			ull w;
			scanf("%llu", &w);
			add(xa, ya, w), add(xb + 1, ya, w), add(xa, yb + 1, w), add(xb + 1, yb + 1, w);
		} else {
			printf("%llu\n", ask(xb, yb) ^ ask(xa - 1, yb) ^ ask(xb, ya - 1) ^ ask(xa - 1, ya - 1));
		}
	}
	return 0;
}