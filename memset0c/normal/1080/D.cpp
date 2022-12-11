#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int inf = 9223372036854775807ll;

int n, k, t[100];
int T;

bool check(int x, int y) {
	double a = (double)x / inf;
	double b = (double)y / inf;
	return (a * b - 1e-4) >= 1;
}

void main() {
	read(T), t[0] = 0; t[1] = 1;
	for (int i = 2; i <= 31; i++)
		t[i] = t[i - 1] + (1ll << i - 1) * (1ll << i - 1);
	while (T--) {
		read(n); read(k); int ans = -1;
		if(n >= 32 || t[n - 1] + 1 >= k) {
			printf("YES %d\n", n - 1);
			continue;
		}
		int now = 1, nowcan = t[n - 1], cnt = 1;
		for (int i = 2; i <= n + 1 && now <= k && i <= 31; i++) {
			if (k - now <= nowcan) {
				ans = n - i + 1;
				break;
			}
			if (i == n + 1) break;
			now += (cnt + 2ll);
			cnt = (1ll << i + 1) - 3;
			if (check(t[n - i], cnt)) nowcan = inf;
			else nowcan += t[n - i] * cnt;
		}
		if (ans != -1) printf("YES %d\n", ans);
		else printf("NO\n");
	}
	return;
}

} signed main() { return ringo::main(), 0; }