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

vector<pii> qry1[N], qry2[N], seg1[N], seg2[N];
vector<int> vec[N];
long long ans[N * 5];
int st[N][18], lg[N], a[N], pre[N], val[N];
int n, q;

int query(int l, int r) {
	int k = lg[r - l + 1];
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

long long sum[N << 2], tag[N << 2];

void update(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void add_tag(int u, int len, long long x) {
	sum[u] += len * x;
	tag[u] += x;
}

void pushdown(int u, int len) {
	if (tag[u]) {
		add_tag(u << 1, (len + 1) / 2, tag[u]);
		add_tag(u << 1 | 1, len / 2, tag[u]);
		tag[u] = 0;
	}
}

void add(int u, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		add_tag(u, R - L + 1, x);
		return;
	}
	pushdown(u, R - L + 1);
	int mid = (L + R) >> 1;
	if (mid >= l) add(u << 1, L, mid, l, r, x);
	if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
	update(u);
}

long long query(int u, int L, int R, int l, int r) {
	if (l <= L && R <= r) return sum[u];
	pushdown(u, R - L + 1);
	int mid = (L + R) >> 1;
	long long ans = 0;
	if (mid >= l) ans += query(u << 1, L, mid, l, r);
	if (mid + 1 <= r) ans += query(u << 1 | 1, mid + 1, R, l, r);
	return ans;
}

void solve(int l, int r) {
	if (l > r) return;
	int pos = pre[query(l, r)];
	if (pos - l <= r - pos) {
		int minn = r + 1;
		for (auto i: vec[a[pos]]) {
			if (pre[i] < pre[a[pos] / i] && pre[i] >= pos) {
				minn = min(minn, pre[a[pos] / i]);
			}
		}
		for (int i = pos; i >= l; i--) {
			if (a[pos] % a[i] == 0) {
				int tmp = pre[a[pos] / a[i]];
				if (tmp > i) minn = min(minn, tmp);
			}
			if (minn != r + 1) seg1[i].emplace_back(max(minn, pos), r);
		}
	} else {
		int maxn = l - 1;
		for (auto i: vec[a[pos]]) {
			if (pre[i] > pre[a[pos] / i] && pre[i] <= pos) {
				maxn = max(maxn, pre[a[pos] / i]);
			}
		}
		for (int i = pos; i <= r; i++) {
			if (a[pos] % a[i] == 0) {
				int tmp = pre[a[pos] / a[i]];
				if (tmp < i) maxn = max(maxn, tmp);
			}
			if (maxn != l - 1) seg2[i].emplace_back(l, min(maxn, pos));
		}
	}
	solve(l, pos - 1);
	solve(pos + 1, r);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	q = read();
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) vec[j].push_back(i);
	}
	for (int i = 1; i <= n; i++) a[i] = read(), pre[a[i]] = i;
	for (int i = 1; i <= q; i++) {
		int l = read(), r = read();
		qry1[l].emplace_back(r, i);
		qry2[r].emplace_back(l, i);
	}
	for (int i = 1; i <= n; i++) st[i][0] = a[i];
	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[0] = -1;
	for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	solve(1, n);
	for (int i = n; i >= 1; i--) {
		for (auto j: seg1[i]) add(1, 1, n, j.first, j.second, 1);
		for (auto j: qry1[i]) ans[j.second] += query(1, 1, n, i, j.first);
	}
	memset(sum, 0, sizeof(sum));
	memset(tag, 0, sizeof(tag));
	for (int i = 1; i <= n; i++) {
		for (auto j: seg2[i]) add(1, 1, n, j.first, j.second, 1);
		for (auto j: qry2[i]) ans[j.second] += query(1, 1, n, j.first, i);
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}