// =================================
//   author: memset0
//   date: 2019.02.08 23:07:55
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
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
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

int n;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int solve(int n) {
    if (n == 1 || n == 2) return 1;
    if (n & 1) return is_prime(n) ? 1 : is_prime(n - 2) ? 2 : 3;
    else return 2;
}

void main() {
    read(n), print(solve(n), '\n');
    int a, b; a = 1, b = 2; int c = a + b / 2;
}

} signed main() { return ringo::main(), 0; }