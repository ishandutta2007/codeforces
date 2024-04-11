#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vp;
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

const int maxn = 2e5 + 10, maxm = 1e6 + 10;
int n, m, p[maxn], pos[maxn];
ll ans[maxm];
struct line {
	int id, x, sy, ey, c;
	friend bool operator < (line a, line b) {
		if (a.x != b.x) return a.x < b.x;
		return a.id < b.id;
	}
};
vector <line> v;
void addrec(int id, int sx, int sy, int ex, int ey) {
	if (!id) {
		v.push_back({id, sx, sy, ey, 1});
		v.push_back({id, ex + 1, sy, ey, -1});
	}
	else {
		v.push_back({id, sx - 1, sy, ey, -1});
		v.push_back({id, ex, sy, ey, 1});
	}
}

struct SegTree {
	ll sum[maxn << 2], add[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { sum[rt] = sum[ls] + sum[rs]; }
	void tag(int rt, int l, int r, ll v) { add[rt] += v, sum[rt] += v * (r - l + 1); }
	void push_down(int rt, int l, int r) {
		if (add[rt]) tag(ls, l, mid, add[rt]), tag(rs, mid + 1, r, add[rt]), add[rt] = 0;
	}
	void update(int rt, int l, int r, int L, int R, ll val) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, l, r, val);
		push_down(rt, l, r), update(ls, l, mid, L, R, val), update(rs, mid + 1, r, L, R, val); push_up(rt);
	}
	ll query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return sum[rt];
		return push_down(rt, l, r), query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
} tr1, tr2;

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) read(p[i]), pos[p[i]] = i;
	for (int i = 1; i <= m; ++i) {
		int l, r; read(l, r);
		addrec(i, l, l, r, r);
	}
	set <int> s;
	s.insert(0), s.insert(n + 1);
	for (int i = n; i >= 1; --i) {
		int k = pos[i]; auto lt = s.lower_bound(k), rt = lt--;
		int L = *lt, R = *rt; s.insert(k);
		vp tmp;
		for (int j = 1; j * j < i; ++j) if (i % j == 0) {
			int l = min(k, min(pos[j], pos[i / j])), r = max(k, max(pos[j], pos[i / j]));
			if (L < l && r < R) tmp.push_back({l, r});
		}
		sort(tmp.begin(), tmp.end());
		vp sta;
		pii lst = {-1, -1};
		for (pii p : tmp) {
			if (p.fir == lst.fir) continue;
			while (sta.size() && sta.back().sec >= p.sec) sta.pop_back();
			sta.push_back(p), lst = p;
		}
		lst = {L, 0};
		for (pii p : sta)
			addrec(0, lst.fir + 1, p.sec, p.fir, R - 1), lst = p;
	}
	sort(v.begin(), v.end());
	for (line p : v) {
		if (!p.id) {
			tr1.update(1, 1, n, p.sy, p.ey, p.c);
			tr2.update(1, 1, n, p.sy, p.ey, p.x * p.c);
		}
		else
		 	ans[p.id] += p.c * (tr1.query(1, 1, n, p.sy, p.ey) * (p.x + 1) - tr2.query(1, 1, n, p.sy, p.ey));
	}
	for (int i = 1; i <= m; ++i) write(ans[i], '\n');
	return 0;
}