#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 1e6 + 10;
int n, m, b[maxn], B;
void sum(int *a) {
	for (int bit = 0; bit < B; ++bit)
		for (int i = 0; i < m; ++i)
			if ((i >> bit) & 1) a[i] ^= a[i ^ (1 << bit)];
}

int main() {
	read(n);
	for (m = 1; m <= n; m <<= 1) ++B;
	for (int i = 0; i < n; ++i) read(b[i]);
	sum(b);
	for (int i = n; i < m; ++i) b[i] = 0;
	reverse(b, b + m);
	sum(b);
	reverse(b, b + m);
	for (int i = n - 1; i >= 0; --i) write(b[i], " \n"[i == 0]);
	return 0;
}