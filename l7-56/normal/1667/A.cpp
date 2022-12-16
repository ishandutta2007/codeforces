#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 5010;
int n,a[maxn];

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i) {
		ll lst = 0, res = 0;
		for (int j = i - 1; j >= 1; --j) {
			ll x = (lst - 1) / a[j] - ((lst - 1) % a[j] != 0);
			lst = a[j] * x, res -= x;
		}
		lst = 0;
		for (int j = i + 1; j <= n; ++j) {
			ll x = (lst + 1) / a[j] + ((lst + 1) % a[j] != 0);
			lst = a[j] * x, res += x;
		}
		ans = min(ans, res);
	}
	write(ans, '\n');
	return 0;
}