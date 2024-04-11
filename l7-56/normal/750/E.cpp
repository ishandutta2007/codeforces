// LUOGU_RID: 91580046
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 2e5 + 10, inf = 1e9;
struct mat {
	int a[5][5];
	mat() { memset(a, 0x3f, sizeof a); }
	friend mat operator * (mat a, mat b) {
		mat c;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				for (int k = 0; k < 5; ++k)
					c.a[i][k] = min(a.a[i][j] + b.a[j][k], c.a[i][k]);
		return c;
	}
} trs[10];
int n, q;
char s[maxn];

struct SegTree {
	mat val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = val[ls] * val[rs]; }
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = trs[s[l] - '0'], void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	mat query(int rt, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[rt];
		if (L > mid) return query(rs, mid + 1, r, L, R);
		if (R <= mid) return query(ls, l, mid, L, R);
		return query(ls, l, mid, L, R) * query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	for (int c = 0; c < 10; ++c) {
		for (int i = 0; i < 5; ++i) {
			trs[c].a[i][i] = 1;
			if (c == 0) trs[c].a[i][i + (i == 1)] = 0;
			else if (c == 1) trs[c].a[i][i + (i == 2)] = 0;
			else if (c == 2) trs[c].a[i][i + (i == 0)] = 0;
			else if (c == 7) trs[c].a[i][i + (i == 3)] = 0;
			else if (c != 6) trs[c].a[i][i] = 0;
			else if (i < 3) trs[c].a[i][i] = 0;
		}
	}
	tr.build(1, 1, n);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		mat p = tr.query(1, 1, n, l, r);
		printf("%d\n", p.a[0][4] < inf ? p.a[0][4] : -1);
	}
	return 0;
}