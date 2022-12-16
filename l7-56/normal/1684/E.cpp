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

const int maxn = 1e5 + 10, inf = 1e9 + 10;
int n, k, a[maxn], c[maxn];
struct SegTree {
	int cnt[maxn << 2], sum[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) {
		cnt[rt] = cnt[ls] + cnt[rs];
		sum[rt] = sum[ls] + sum[rs];
	}
	void build(int rt, int l, int r) {
		if (l == r) return void(cnt[rt] = sum[rt] = 0);
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void update(int rt, int l, int r, int pos, int val) {
		if (pos < l || pos > r) return;
		if (l == r) return cnt[rt] += val, sum[rt] += val * l, void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid + 1, r, pos, val); push_up(rt);
	}
	int query(int rt, int l, int r, int s) {
		if (l == r) return min(cnt[rt], s / l);
		if (sum[ls] >= s) return query(ls, l, mid, s);
		return cnt[ls] + query(rs, mid + 1, r, s - sum[ls]);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;
void work() {
	read(n, k);
	for (int i = 0; i <= n; ++i) c[i] = 0;
	vector <int> b;
	for (int i = 1; i <= n; ++i) {
		read(a[i]), b.push_back(a[i]);
		if (a[i] <= n) c[a[i]]++;
	}
	sort(b.begin(), b.end());
	int col = 0, ans = inf;
	tr.build(1, 1, n);
	for (int i = 0, j; i < (int) b.size(); i = j) {
		for (j = i; j < (int) b.size() && b[i] == b[j]; ++j);
		++col, tr.update(1, 1, n, j - i, 1);
	}
	for (int x = 0, prec = 0; x <= n; ++x) {
		tr.update(1, 1, n, c[x], -1);
		if (c[x] + max(0, prec - c[x]) <= k) {
			int res = col + prec - (c[x] > 0) - tr.query(1, 1, n, k - c[x]) - x;
			ans = min(ans, res);
		}
		prec += !c[x];
	}
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}