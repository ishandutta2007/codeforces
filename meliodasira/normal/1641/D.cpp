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

const int N = 1e5 + 5;

__int128 seq[N * 32], val[N][32];
int a[N][5], id[N], w[N], ii[N][32], cnt[N * 32];
int n, m, len, ans = 2000000001;

bool cmp(int i, int j) { return w[i] < w[j]; }

void solve(int l, int r, vector<int> vec) {
	int mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) {
		for (int j = 1; j < (1 << m); j++) {
			++cnt[ii[id[i]][j]];
		}
	}
	vector<int> L, R;
	for (auto i: vec) {
		int now = mid - l + 1;
		for (int j = 1; j < (1 << m); j++) {
			if (__builtin_popcount(j) & 1)
				now -= cnt[ii[i][j]];
			else
				now += cnt[ii[i][j]];
		}
		if (l == r) {
			if (now) ans = min(ans, w[i] + w[id[l]]);
		} else {
			if (now)
				L.push_back(i);
			else
				R.push_back(i);
		}
	}
	for (int i = l; i <= mid; i++) {
		for (int j = 1; j < (1 << m); j++) {
			--cnt[ii[id[i]][j]];
		}
	}
	if (l != r) {
		solve(l, mid, L);
		solve(mid + 1, r, R);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	rep(i, 1, n) {
		rep(j, 0, m - 1) a[i][j] = read();
		sort(a[i], a[i] + m);
		rep(j, 1, (1 << m) - 1) {
			rep(k, 0, m - 1) {
				if ((j >> k) & 1) {
					val[i][j] = val[i][j] * 1000000001 + a[i][k];
				}
			}
			seq[++len] = val[i][j];
		}
		w[i] = read();
		id[i] = i;
	}
	sort(seq + 1, seq + len + 1);
	rep(i, 1, n) {
		rep(j, 1, (1 << m) - 1) {
			ii[i][j] = lower_bound(seq + 1, seq + len + 1, val[i][j]) - seq;
		}
	}
	sort(id + 1, id + n + 1, cmp);
	vector<int> vec;
	rep(i, 1, n) vec.push_back(i);
	solve(1, n, vec);
	if (ans == 2000000001) ans = -1;
	printf("%d\n", ans);
}