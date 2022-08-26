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

vector<int> vec[N];
int a[N], b[N], l[N], r[N], mx[N], pos[N], tag[N];
int T, n, m, ans, maxn;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		for (int i = 1; i <= n; i++) a[i] = read(), b[i] = a[i], vec[i].clear(), mx[i] = tag[i] = 0;
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) {
			a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
			pos[i] = vec[a[i]].size();
			vec[a[i]].push_back(i);
		}
		for (int i = 1; i <= m; i++) {
			l[i] = read();
			r[i] = read();
			mx[l[i]] = max(mx[l[i]], r[i]);
		}
		for (int i = 2; i <= n; i++) mx[i] = max(mx[i], mx[i - 1]);
		maxn = 0;
		for (int i = 1; i <= n; i++) {
			if (mx[i] < i) continue;
			int pp = upper_bound(vec[a[i]].begin(), vec[a[i]].end(), mx[i]) - vec[a[i]].begin() - 1;
			if (pos[i] != pp) {
				maxn = max(maxn, vec[a[i]][pp - 1]);
				tag[vec[a[i]][pos[i]] + 1] = max(tag[vec[a[i]][pos[i]] + 1], vec[a[i]][pp]);
				tag[vec[a[i]][pos[i] + 1] + 1] = max(tag[vec[a[i]][pos[i] + 1] + 1], n + 1);
			}
		}
		if (!maxn) {
			printf("0\n");
			continue;
		}
		ans = n;
		for (int i = 1; i <= n; i++) {
			maxn = max(maxn, max(i, tag[i]));
			if (maxn != n + 1) ans = min(ans, maxn - i + 1);
		}
		printf("%d\n", ans);
	}
}