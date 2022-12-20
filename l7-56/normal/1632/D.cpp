#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n,a[maxn];

struct SegTree {
	int val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	void push_up(int rt) { val[rt] = gcd(val[ls], val[rs]); }
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = a[l], void();
		int mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r); push_up(rt);
	}
	void update(int rt, int l, int r, int pos, int _val) {
		if (l == r) return val[rt] = _val, void();
		int mid = (l + r) >> 1;
		if (pos <= mid) update(ls, l, mid, pos, _val);
		else update(rs, mid + 1, r, pos, _val);
		push_up(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return val[rt];
		int mid = (l + r) >> 1;
		return gcd(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
}T;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	T.build(1, 1, n);
	for (int i = 1, pos = 1, cnt = 0; i <= n; ++i) {
		if (a[i] == 1) {
			printf("%d ", ++cnt);
			continue;
		}
		while (pos <= i && T.query(1, 1, n, pos, i) < i - pos + 1) ++pos;
		if (pos <= i && T.query(1, 1, n, pos, i) == i - pos + 1)
			a[i] = 1, T.update(1, 1, n, i, 1), cnt++;
		printf("%d ", cnt);
	}
	return 0;
}