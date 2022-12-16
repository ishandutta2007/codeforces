#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e6 + 10;
int n, m, h[maxn], pos[maxn];
struct SegTree {
	int mx[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { mx[rt] = max(mx[ls], mx[rs]); }
	void update(int rt, int l, int r, int pos, int val) {
		if (l == r) return void(mx[rt] = val);
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid + 1, r, pos, val), push_up(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if (L > R || L > r || R < l) return 0;
		if (L <= l && r <= R) return mx[rt];
		return max(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
} tr1, tr2;

int main() {
	read(n, m);
	set <int> s;
	for (int i = 1; i <= m; ++i) {
		int op, p, x; read(op);
		if (op == 1) {
			read(p), read(h[p]);
			h[p] = h[p] + m - i, pos[h[p]] = p, s.insert(p);
			for (int j = m - i; j <= h[p]; ++j)
				if (pos[j]) tr1.update(1, 1, n, pos[j], 0);
			for (int j = h[p]; j >= m - i; --j)
				if (pos[j]) {
					int val = tr1.query(1, 1, n, pos[j], n) + 1;
					tr1.update(1, 1, n, pos[j], val);
					tr2.update(1, 1, m + 10, j, val);
				}
		}
		else {
			vector <int> v; read(x);
			for (int j = 1; j < x; ++j)
				v.push_back(*s.begin()), s.erase(s.begin()),
				tr2.update(1, 1, m + 10, h[v.back()], 0);
			p = *s.begin(), s.erase(s.begin());
			tr1.update(1, 1, n, p, 0), tr2.update(1, 1, m + 10, h[p], 0);
			pos[h[p]] = 0, h[p] = 0;
			for (int j = x - 2; j >= 0; --j) {
				int val = tr2.query(1, 1, m + 10, h[v[j]], m + 10) + 1;
				tr1.update(1, 1, n, v[j], val);
				tr2.update(1, 1, m + 10, h[v[j]], val);
				s.insert(v[j]);
			}
		}
		write(tr1.mx[1], '\n');
	}
	return 0;
}