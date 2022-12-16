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

int n,a;

int main() {
	read(n), a = n / 3;
	if (n == 3 * a) {
		write(a * 2, '\n');
		write(1, ' ', 1, '\n');
		for (int i = 1; i <= a - 1; ++i) write(i + 1, ' ', a + 1 - i, '\n');
		for (int i = 1; i <= a; ++i) write(i + a, ' ', a * 2 + 1 - i, '\n');
	}
	else {
		write(a * 2 + 1, '\n');
		for (int i = 1; i <= a; ++i) write(i, ' ', a + 1 - i, '\n');
		for (int i = 1; i <= a + 1; ++i) write(i + a, ' ', 2 * a + 2 - i, '\n');
	}
	return 0;
}