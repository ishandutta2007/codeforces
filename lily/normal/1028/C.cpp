#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)
#define INF 0x3f3f3f3f

int n;
struct Node {
	int x1, y1, x2, y2;
	void r() {read(x1); read(y1); read(x2); read(y2);}
	bool empty() {
		return x1 > x2 || y1 > y2;
	}
} a[999989];

Node ins(Node x, Node y) {
	return Node{max(x.x1, y.x1), max(x.y1, y.y1), min(x.x2, y.x2), min(x.y2, y.y2)};
}

void solve(int l, int r, Node full = (Node) {-INF, -INF, INF, INF}) {
	if (full.empty()) return;
	if (l == r) {
		if (!full.empty()) {
			printf("%d %d\n", full.x1, full.y1);
			exit(0);
		}
		return;
	}
	int mid = (l + r) >> 1;
	Node x = full, y = full;
	for (int i = l; i <= mid; i++) x = ins(x, a[i]);
	for (int i = mid + 1; i <= r; i++) y = ins(y, a[i]);
	solve(l, mid, y); solve(mid + 1, r, x);
}


int main() {
	read(n);
	for (int i = 1; i <= n; i++) a[i].r();
	solve(1, n);
	return 0;
}