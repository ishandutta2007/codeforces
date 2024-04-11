// =================================
//   author: memset0
//   date: 2018.12.06 19:22:54
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

int a, b, base, tbase, u;

int ask(int x, int y) {
    // printf("ask %d %d %d %d %d %d\n", x, y, a, b, x | a, y | b);
    x |= a, y |= b;
    if (base == -1) std::swap(x, y);
    printf("? %d %d\n", x, y); 
    fflush(stdout);
    int ret; read(ret);
    ret *= base;
    // printf(">>> %d\n", ret);
    return ret;
}

void solve(int s, int base) {
    // printf("solve %d %d\n", s, base);
    for (int i = s; i >= 0; i--) {
        u = ask(1 << i, 0);
        // printf(">>> %d\n", u);
        if (u == -1) {
            a |= 1 << i;
            b |= 1 << i;
        }
    }
    if (base == 1) printf("! %d %d\n", a, b);
    else printf("! %d %d\n", b, a);
    exit(0);
}

void main() {
    printf("? %d %d\n", 0, 0);
    fflush(stdout);
    read(base);
    if (!base) base = 1, solve(29, 1);
    if (base == -1) std::swap(a, b);
    for (int i = 29; i >= 0; i--) {
        u = ask(1 << i, 1 << i);
        if (u == 0 || u == 1) {
            u = ask(1 << i, 0);
            if (u == -1) {
                a |= 1 << i;
                b |= 1 << i;
            }
        } else {
            a |= 1 << i;
            tbase = ask(0, 0);
            if (!tbase) solve(i - 1, base);
            if (tbase == -1) std::swap(a, b), base *= -1;
        }
    }
    solve(-1, base);
}

} signed main() { return ringo::main(), 0; }