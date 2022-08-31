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

char c[N];
int x[N], y[N];
int T, n, m;
long long ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		scanf("%s", c + 1);
		m = strlen(c + 1);
		if (c[1] == 'D') {
			for (int i = 1; i <= m; i++) {
				if (c[i] == 'D')
					c[i] = 'R';
				else
					c[i] = 'D';
			}
		}
		int same = 1;
		for (int i = 2; i <= m; i++) {
			if (c[i] != c[i - 1]) {
				same = 0;
			}
		}
		if (same) {
			printf("%d\n", n);
			continue;
		}
		x[0] = y[0] = 1;
		for (int i = 1; i <= m; i++) {
			x[i] = x[i - 1];
			y[i] = y[i - 1];
			if (c[i] == 'R') ++x[i];
			if (c[i] == 'D') ++y[i];
		}
		ans = 1ll * (n - x[m] + 1) * (n - y[m] + 1) + 1;
		int D = 0;
		for (int i = 1; i < m; i++) {
			if (c[i] == 'D') D = 1;
			if (c[i] != c[i + 1]) {
				if (c[i] == 'R')
					ans += n - x[m] + 1;
				else
					ans += n - y[m] + 1;
			} else {
				if (c[i] == 'R') {
					if (D)
						ans += n - y[m] + 1;
					else
						++ans;
				} else
					ans += n - x[m] + 1;
			}
		}
		printf("%lld\n", ans);
	}
}