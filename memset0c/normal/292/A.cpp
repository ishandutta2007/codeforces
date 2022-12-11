// =================================
//   author: memset0
//   date: 2018.12.28 13:06:25
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)

namespace ringo {
typedef long long ll;
typedef unsigned long long ull;

const int IN_LEN = 1000000, OUT_LEN = 10000000;
char buf[IN_LEN], obuf[OUT_LEN], *ooh = obuf;
inline char read() {
	static char *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template <class T> inline void read(T &x) {
	static bool f = 0; static char c = read();
	for (x = 0; !isdigit(c); c = read()) { f ^= c == '-'; if (c == -1) return; }
	for (; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (f) x = -x;
}
template<class T> inline void print(T x) {
	static int buf[30], cnt;
	if (!x) { print('0'); return; }
	if (x < 0) print('-'), x = -x;
	for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + '0';
	while (cnt) print((char)buf[cnt--]);
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), print(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

int n, lst, a, b, tim, max;

void main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a), read(b);
        lst = std::max(lst - a + tim, 0) + b;
        max = std::max(max, lst);
        tim = a;
    }
	print(tim + lst, ' '), print(max, '\n');
}

} signed main() { return ringo::main(), ringo::flush(), 0; }