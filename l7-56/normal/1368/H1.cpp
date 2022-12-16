#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void read(int &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}

void read(char *s) {
	int i = 1; s[i] = getchar();
	for (; s[i] == ' ' || s[i] == '\n'; s[i] = getchar());
	for (; s[i] != ' ' && s[i] != '\n'; s[i] = getchar()) ++i;
}

void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

const int maxn = 5e5 + 10, inf = 1e9;
int n,m,q;
struct opt {
	char op; int l, r;
}b[maxn];
char su[maxn],sd[maxn],sl[maxn],sr[maxn];
int ans[maxn];
namespace solve {
	struct Matrix {
		int a[2][2],h,w;
		Matrix() : h(0), w(0) {}
		Matrix(int h, int w) : h(h), w(w) {}
		Matrix(char cu, char cd) : h(2), w(2) {
			int cnt = (cu == 'R') + (cd == 'R');
			a[0][0] = cnt, a[0][1] = n + 2 - cnt;
			a[1][0] = n + cnt, a[1][1] = 2 - cnt;
		}
		void Swap() { swap(a[0][0], a[1][1]), swap(a[1][0], a[0][1]); }
		friend Matrix operator * (Matrix p, Matrix q) {
			Matrix ret(p.h, q.w);
			ret.a[0][0] = min(p.a[0][0] + q.a[0][0], p.a[0][1] + q.a[1][0]);
			ret.a[0][1] = min(p.a[0][0] + q.a[0][1], p.a[0][1] + q.a[1][1]);
			ret.a[1][0] = min(p.a[1][0] + q.a[0][0], p.a[1][1] + q.a[1][0]);
			ret.a[1][1] = min(p.a[1][0] + q.a[0][1], p.a[1][1] + q.a[1][1]);
			return ret;
		}
	};
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	struct SegTree1 {
		int sum[maxn << 2][2], rev[maxn << 2];
		void push_up(int rt) {
			sum[rt][0] = sum[ls][0] + sum[rs][0];
			sum[rt][1] = sum[ls][1] + sum[rs][1];
		}
		void tag(int rt) { rev[rt] ^= 1, swap(sum[rt][0], sum[rt][1]); }
		void push_down(int rt) { if (rev[rt]) tag(ls), tag(rs), rev[rt] = 0; }
		void build(int rt, int l, int r, char *s) {
			sum[rt][0] = sum[rt][1] = rev[rt] = 0;
			if (l == r) return sum[rt][s[l] == 'R'] = 1, void();
			build(ls, l, mid, s), build(rs, mid + 1, r, s), push_up(rt);
		}
		void update(int rt, int l, int r, int L, int R) {
			if (L > r || R < l) return;
			if (L <= l && r <= R) return tag(rt);
			push_down(rt), update(ls, l, mid, L, R), update(rs, mid + 1, r, L, R), push_up(rt);
		}
	}Tl, Tr;
	struct SegTree2 {
		Matrix val[maxn << 2][2]; int rev[maxn << 2][2];
		void push_up(int rt) {
			val[rt][0] = val[ls][0] * val[rs][0];
			val[rt][1] = val[ls][1] * val[rs][1];
		}
		void build(int rt, int l, int r) {
			rev[rt][0] = rev[rt][1] = 0;
			if (l == r) {
				val[rt][0] = Matrix(su[l], sd[l]);
				val[rt][1] = Matrix(su[l], sd[l] == 'R' ? 'B' : 'R');
				return;
			}
			build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
		}
		void tag(int rt, int c) {
			if (!c) rev[rt][0] ^= 1, val[rt][0].Swap(), val[rt][1].Swap();
			else rev[rt][1] ^= 1, swap(val[rt][0], val[rt][1]);
		}
		void push_down(int rt) {
			if (rev[rt][0]) tag(ls, 0), tag(rs, 0), rev[rt][0] = 0;
			if (rev[rt][1]) tag(ls, 1), tag(rs, 1), rev[rt][1] = 0;
		}
		void update(int rt, int l, int r, int L, int R, int c) {
			if (L > r || R < l) return;
			if (L <= l && r <= R) return tag(rt, c);
			push_down(rt), update(ls, l, mid, L, R, c), update(rs, mid + 1, r, L, R, c), push_up(rt);
		}
	}T;
	#undef ls
	#undef rs
	#undef mid
	int query() {
		Matrix st(1, 2);
		st.a[0][0] = Tl.sum[1][1], st.a[0][1] = Tl.sum[1][0];
		st = st * T.val[1][0];
		return min(st.a[0][0] + Tr.sum[1][1], st.a[0][1] + Tr.sum[1][0]);
	}
	void work() {
		Tl.build(1, 1, n, sl);
		Tr.build(1, 1, n, sr);
		T.build(1, 1, m);
		ans[0] = min(ans[0], query());
		for (int i = 1; i <= q; ++i) {
			if (b[i].op == 'L') Tl.update(1, 1, n, b[i].l, b[i].r);
			else if (b[i].op == 'R') Tr.update(1, 1, n, b[i].l, b[i].r);
			else {
				if (b[i].op == 'U') T.update(1, 1, m, b[i].l, b[i].r, 0);
				T.update(1, 1, m, b[i].l, b[i].r, 1);
			}
			ans[i] = min(ans[i], query());
		}
	}
}

int main() {
	// freopen("line.in", "r", stdin), freopen("line.out", "w", stdout);
	read(n), read(m), read(q), read(sl), read(sr), read(su), read(sd);
	ans[0] = inf;
	for (int i = 1; i <= q; ++i) {
		char opp[4];
		read(opp), read(b[i].l), read(b[i].r);
		b[i].op = opp[1], ans[i] = inf;
	}
	solve :: work();
	// for (int i = 0; i <= q; ++i) printf("%d\n", ans[i]);
	// printf("---------------------\n");
	swap(n, m), swap(su, sl), swap(sd, sr);
	for (int i = 1; i <= q; ++i) {
		if (b[i].op == 'U') b[i].op = 'L';
		else if (b[i].op == 'D') b[i].op = 'R';
		else if (b[i].op == 'L') b[i].op = 'U';
		else if (b[i].op == 'R') b[i].op = 'D';
	}
	solve :: work();
	for (int i = 0; i <= q; ++i) write(ans[i]), putchar('\n');
	return 0;
}