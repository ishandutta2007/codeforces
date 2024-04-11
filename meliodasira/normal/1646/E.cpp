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

const int N = 1e6 + 5;

int mx[N], v[20];
int n, m;
long long ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	ans = 1 + 1ll * (n - 1) * m;
	for (int i = 2; i <= n; i++) {
		int cnt = 0, now = 1;
		while (1ll * now * i <= n) {
			now *= i;
			++cnt;
			mx[now] = max(mx[now], cnt);
		}
	}
	for (int i = 2; i <= 20; i++) {
		for (int j = 1; j <= m; j++) {
			for (int x = (i * j + m - 1) / m; x < i; x++) {
				if (i * j % x == 0) {
					++v[i];
					break;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) ans -= v[mx[i]];
	printf("%lld\n", ans);
}