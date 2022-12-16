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

const int maxn = 1e5 + 10;
int a[maxn],n;
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	sort(a + 1, a + n + 1);
	int cnt = 1, len = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1]) len++;
		else len = 1;
		cnt = max(cnt, len);
	}
	int ans = n - cnt;
	while (cnt < n) ans++, cnt <<= 1;
	write(ans, '\n');
}

int main() {
	int t; read(t);
	while (t--) work();
	return 0;
}