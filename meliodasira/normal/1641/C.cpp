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

vector<int> tt[N];
int opt[N], x[N], y[N], z[N], vis[N];
int n, q;

int tag[N << 2], sum[N << 2];

void update(int u, int l, int r) {
	if (tag[u]) {
		sum[u] = r - l + 1;
	} else if (l != r) {
		sum[u] = sum[u << 1] + sum[u << 1 | 1];
	} else {
		sum[u] = 0;
	}
}

void add(int u, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		tag[u] += x;
		update(u, L, R);
		return;
	}
	int mid = (L + R) >> 1;
	if (mid >= l) add(u << 1, L, mid, l, r, x);
	if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
	update(u, L, R);
}

int query(int u, int L, int R, int l, int r) {
	if (tag[u]) return min(r, R) - max(l, L) + 1;
	if (l <= L && R <= r) return sum[u];
	int mid = (L + R) >> 1, ans = 0;
	if (mid >= l) ans += query(u << 1, L, mid, l, r);
	if (mid + 1 <= r) ans += query(u << 1 | 1, mid + 1, R, l, r);
	return ans;
}

int getpos(int u, int L, int R, int l, int r) {
	if (tag[u] || sum[u] == R - L + 1) return -1;
	if (L == R) return L;
	int mid = (L + R) >> 1;
	if (mid >= l) {
		int tmp = getpos(u << 1, L, mid, l, r);
		if (tmp != -1) return tmp;
	}
	return getpos(u << 1 | 1, mid + 1, R, l, r);
}

void solve(int l, int r, vector<int> vec) {
	int mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) {
		if (opt[i] == 2 && z[i] == 0) {
			add(1, 1, n, x[i], y[i], 1);
		}
	}
	vector<int> L, R;
	for (auto i: vec) {
		if (query(1, 1, n, x[i], y[i]) == y[i] - x[i])
			L.push_back(i);
		else
			R.push_back(i);
	}
	if (l == r) {
		for (auto i: L) {
			int pos = getpos(1, 1, n, x[i], y[i]);
			tt[max(i, l)].push_back(pos);
		}
		for (int i = l; i <= mid; i++) {
			if (opt[i] == 2 && z[i] == 0) {
				add(1, 1, n, x[i], y[i], -1);
			}
		}
		return;
	}
	solve(mid + 1, r, R);
	for (int i = l; i <= mid; i++) {
		if (opt[i] == 2 && z[i] == 0) {
			add(1, 1, n, x[i], y[i], -1);
		}
	}
	solve(l, mid, L);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	q = read();
	vector<int> vec;
	rep(i, 1, q) {
		opt[i] = read();
		if (opt[i] == 0) opt[i] = 2;
		if (opt[i] == 1) x[i] = read();
		if (opt[i] == 2) {
			x[i] = read(), y[i] = read(), z[i] = read();
			if (z[i] == 1) vec.push_back(i);
		}
	}
	solve(1, q, vec);
	rep(i, 1, q) {
		if (opt[i] == 1) {
			if (query(1, 1, n, x[i], x[i]))
				printf("NO\n");
			else if (vis[x[i]])
				printf("YES\n");
			else
				printf("N/A\n");
		}
		if (opt[i] == 2) {
			if (z[i] == 0) add(1, 1, n, x[i], y[i], 1);
		}
		for (auto j: tt[i]) vis[j] = 1;
	}
}