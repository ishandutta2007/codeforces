#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

int n, m;

int main() {
    read(n), read(m);
    for (int i = 1, j = n; i <= j; i++, j--) {
        if (i == j) {
            for (int u = 1, v = m; u <= v; u++, v--) {
                printf("%d %d\n", i, u);
                if (u != v) printf("%d %d\n", i, v);
            }
        } else {
            for (int k = 1; k <= m; k++) {
                printf("%d %d\n", i, k);
                printf("%d %d\n", j, m - k + 1);
            }
        }
    }
}