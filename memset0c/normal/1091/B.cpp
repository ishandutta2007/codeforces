// =================================
//   author: memset0
//   date: 2018.12.30 22:39:31
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)

namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1010;
int n;
struct node{ int a, b; } w[N], q[N];
 
inline bool compare(node a,node b) {if(a.a==b.a) return a.b<b.b; return a.a<b.a;}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(w[i].a), read(w[i].b);
	for (int i = 1; i <= n; i++) read(q[i].a), read(q[i].b);
	std::sort(w + 1, w + n + 1, compare);
	std::sort(q + 1, q + n + 1, compare);
	printf("%d %d\n", w[1].a + q[n].a, w[1].b + q[n].b);
} 

} signed main() { return ringo::main(), 0; }