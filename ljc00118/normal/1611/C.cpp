#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

int a[N], b[N * 2], c[N], d[N * 2];
int T, n;

pii sol1(int *a, int *b) {
    int l = n + 1, r = n, L = 1, R = n;
    while (L <= R) {
        int dir = (a[L] >= a[R]);
        if (dir == 0) {
            --l;
            b[l] = a[L];
            ++L;
        } else {
            ++r;
            b[r] = a[R];
            --R;
        }
    }
    return make_pair(l, r);
}

pii sol2(int *a, int *b) {
    int l = n + 1, r = n, L = 1, R = n;
    while (L <= R) {
        int dir = (a[L] > a[R]);
        if (dir == 0) {
            --l;
            b[l] = a[L];
            ++L;
        } else {
            ++r;
            b[r] = a[R];
            --R;
        }
    }
    return make_pair(l, r);
}

bool check() {
    pii x = sol1(c, d);
    int cando = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != d[x.first + i - 1]) {
            cando = 0;
            break;
        }
    }
    if (cando) {
        for (int i = 1; i <= n; i++) print(c[i], i == n ? '\n' : ' ');
        return 1;
    }
    x = sol2(c, d);
    cando = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != d[x.first + i - 1]) {
            cando = 0;
            break;
        }
    }
    if (cando) {
        for (int i = 1; i <= n; i++) print(c[i], i == n ? '\n' : ' ');
        return 1;
    }
    return 0;
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        pii x = sol1(a, b);
        for (int i = 1; i <= n; i++) c[i] = b[i + x.first - 1];
        if (check()) continue;
        x = sol2(a, b);
        for (int i = 1; i <= n; i++) c[i] = b[i + x.first - 1];
        if (check()) continue;
        puts("-1");
    }
    return 0;
}