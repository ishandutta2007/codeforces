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

void work() {
	int n, r1, c1, r2, c2, r3, c3, x, y;
	read(n, r1, c1, r2, c2, r3, c3, x, y);
	ll R = (r1 == r2 ? r1 : r3), C = (c1 == c2 ? c1 : c3);
	if (((x ^ R) & 1) && ((y ^ C) & 1)) return write("NO\n");
	if (x == R || y == C) return write("YES\n");
	if ((R == 1 || R == n) && (C == 1 || C == n)) return write("NO\n");
	write("YES\n");
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}