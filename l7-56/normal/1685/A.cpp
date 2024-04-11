#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	if (n & 1) return write("NO\n");
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; ++i)
		b[2 * i - 1] = a[i], b[2 * i] = a[i + n / 2];
	b[0] = b[n], b[n + 1] = b[1];
	for (int i = 1; i <= n; i += 2)
		if (b[i] == b[i - 1] || b[i] == b[i + 1]) return write("NO\n");
	write("YES\n");
	for (int i = 1; i <= n; ++i) write(b[i], " \n"[i == n]);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}