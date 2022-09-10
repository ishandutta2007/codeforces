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

int a[N], b[N], t[N];
long long s[N];
int n, m;

int exgcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read(), b[i] = read();
		s[0] += b[i];
		t[i] = a[i] - b[i];
	}
	sort(t + 1, t + n + 1);
	reverse(t + 1, t + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + t[i];
	m = read();
	for (int i = 1; i <= m; i++) {
		int a = read(), b = read(), x, y;
		int d = exgcd(a, b, x, y);
		int step = b / d;
		x = (1ll * x * (n / d) % step + step) % step;
		if (1ll * x * a > n || n % d != 0) {
			printf("-1\n");
			continue;
		}
		long long len = 1ll * step * a;
		x *= a;
		int l = 1, r = (n - x) / len, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (s[x + mid * len] > s[x + (mid - 1) * len])
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		printf("%lld\n", s[x + ans * len]);
	}
}