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

const int N = 3e5 + 5;

vector<pii> qry[N];
vector<int> vec[N];
long long f[N], ans[N];
int x[N], w[N], l[N], r[N], st[N];
int n, q, top;

void add(int x, long long y) {
	while (x <= n) {
		f[x] = min(f[x], y);
		x += (x & -x);
	}
}

long long query(int x) {
	long long ans = 8e18;
	while (x) {
		ans = min(ans, f[x]);
		x &= (x - 1);
	}
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	memset(f, 0x7f, sizeof(f));
	n = read();
	q = read();
	rep(i, 1, n) x[i] = read(), w[i] = read();
	rep(i, 1, q) {
		int l = read(), r = read();
		qry[l].emplace_back(r, i);
	}
	rep(i, 1, n) {
		while (top && w[st[top]] >= w[i]) --top;
		l[i] = st[top];
		st[++top] = i;
	}
	top = 0;
	per(i, n, 1) {
		while (top && w[st[top]] >= w[i]) --top;
		r[i] = st[top];
		st[++top] = i;
	}
	rep(i, 1, n - 1) {
		vec[i].push_back(i + 1);
	}
	rep(i, 1, n) {
		if (l[i] && r[i]) {
			vec[l[i]].push_back(r[i]);
		}
	}
	per(i, n, 1) {
		for (auto j: vec[i]) {
			add(j, 1ll * (x[j] - x[i]) * (w[i] + w[j]));
		}
		for (auto j: qry[i]) {
			ans[j.second] = query(j.first);
		}
	}
	rep(i, 1, q) printf("%lld\n", ans[i]);
}