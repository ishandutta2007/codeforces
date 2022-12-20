#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1e5 + 10;
int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444};
int ask(int x) { return upper_bound(lucky, lucky + 30, x) - lucky; }
int n, m, a[maxn];
struct SegTree {
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	int mn[maxn << 2], cnt[maxn << 2], add[maxn << 2], pos[maxn << 2];
	void push_up(int rt) { mn[rt] = min(mn[ls], mn[rs]), cnt[rt] = cnt[ls] + cnt[rs]; }
	void tag(int rt, int v) {
		mn[rt] += v, cnt[rt] = 0, add[rt] += v;
		if (pos[rt]) a[pos[rt]] -= v;
	}
	void push_down(int rt) { if (add[rt]) tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = 0; }
	void build(int rt, int l, int r) {
		add[rt] = 0;
		if (l == r) {
			int y = ask(a[l]); pos[rt] = l;
			mn[rt] = lucky[y] - a[l];
			cnt[rt] = (lucky[y - 1] == a[l]);
			return;
		}
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void update(int rt, int l, int r, int L, int R, int x) {
		if (L > r || R < l || L > R) return;
		if (L <= l && r <= R) {
			if (mn[rt] > x) return tag(rt, -x);
			if (l == r) {
				a[l] += x;
				int y = ask(a[l]);
				mn[rt] = lucky[y] - a[l];
				cnt[rt] = (lucky[y - 1] == a[l]);
				return;
			}
		}
		push_down(rt), update(ls, l, mid, L, R, x), update(rs, mid + 1, r, L, R, x), push_up(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l || L > R) return 0;
		if (L <= l && r <= R) return cnt[rt];
		return push_down(rt), query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	tr.build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		char opt[10]; int l, r, d;
		scanf("%s", opt);
		if (opt[0] == 'a') {
			scanf("%d%d%d", &l, &r, &d);
			tr.update(1, 1, n, l, r, d);
		}
		else {
			scanf("%d%d", &l, &r);
			printf("%d\n", tr.query(1, 1, n, l, r));
		}
	}
	return 0;
}