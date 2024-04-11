#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 2e5 + 5;

int n = 200000, q, d;

struct fenwick {
	int f[N];

	void add(int x, int y) {
		while (x <= n) {
			f[x] += y;
			x += (x & -x);
		}
	}

	int query(int x) {
		if (x < 0) return 0;
		int ans = 0;
		while (x) {
			ans += f[x];
			x &= (x - 1);
		}
		return ans;
	}
} tr;

long long sum[N << 2];
int tag[N << 2], cnt[N << 2];

void update(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	cnt[u] = cnt[u << 1] + cnt[u << 1 | 1];
}

void add_tag(int u, int x) {
	sum[u] += 1ll * cnt[u] * x;
	tag[u] += x;
}

void pushdown(int u) {
	if (tag[u]) {
		add_tag(u << 1, tag[u]);
		add_tag(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}
}

void add(int u, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		add_tag(u, x);
		return;
	}
	pushdown(u);
	int mid = (L + R) >> 1;
	if (mid >= l) add(u << 1, L, mid, l, r, x);
	if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
	update(u);
}

void modify(int u, int l, int r, int x, int s, int c) {
	if (l == r) {
		sum[u] = s;
		cnt[u] = c;
		return;
	}
	pushdown(u);
	int mid = (l + r) >> 1;
	if (mid >= x)
		modify(u << 1, l, mid, x, s, c);
	else
		modify(u << 1 | 1, mid + 1, r, x, s, c);
	update(u);
}

long long query(int u, int L, int R, int l, int r) {
	if (l <= L && R <= r) return sum[u];
	pushdown(u);
	int mid = (L + R) >> 1;
	long long ans = 0;
	if (mid >= l) ans += query(u << 1, L, mid, l, r);
	if (mid + 1 <= r) ans += query(u << 1 | 1, mid + 1, R, l, r);
	return ans;
}

int vis[N];
long long ans;

long long c2(int x) { return 1ll * x * (x - 1) / 2; }

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	q = read();
	d = read();
	while (q--) {
		int x = read();
		if (vis[x]) {
			ans -= c2(tr.query(x - 1) - tr.query(x - d - 1));
			add(1, 1, n, x + 1, min(n, x + d), -1);
			ans -= query(1, 1, n, x + 1, min(n, x + d));
			modify(1, 1, n, x, 0, 0);
			tr.add(x, -1);
		} else {
			int tmp = tr.query(x - 1) - tr.query(x - d - 1);
			ans += c2(tmp);
			ans += query(1, 1, n, x + 1, min(n, x + d));
			add(1, 1, n, x + 1, min(n, x + d), 1);
			modify(1, 1, n, x, tmp, 1);
			tr.add(x, 1);
		}
		vis[x] ^= 1;
		printf("%lld\n", ans);
	}
}