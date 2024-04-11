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

const int N = 2e5 + 5;

int n, a[N], q, pos[N], suf[N];

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    read(q);
    for (int i = 1; i <= q; i++) {
        int op; read(op);
        if (op == 1) {
            int p, x; read(p), read(x);
            a[p] = x, pos[p] = i;
        } else {
            int x; read(x);
            suf[i] = x;
        }
    }
    for (int i = q - 1; ~i; i--) chkMax(suf[i], suf[i + 1]);

    for (int i = 1; i <= n; i++) {
        printf("%d ", max(a[i], suf[pos[i]]));
    }
}