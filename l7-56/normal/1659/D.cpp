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

const int maxn = 2e5 + 10;
ll n,c[maxn],a[maxn],d[maxn];
void work() {
	read(n);
	ll k = 0;
	for (int i = 1; i <= n; ++i) read(c[i]), k += c[i], d[i] = 0;
	k /= n;
	for (int i = n, sd = 0; i >= 1; --i) {
		sd += d[i];
		a[i] = (c[i] + sd == i);
		if (k) sd--, d[i - k]++;
		if (a[i]) --k;
	}
	for (int i = 1; i <= n; ++i) write(a[i], " \n"[i == n]);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}