// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5;

int n, x[N];
LL t, a[N], L[N], R[N];

int c[N];
 
int main() {
    read(n); read(t);
    for (int i = 1; i <= n; i++) read(a[i]), L[i] = a[i] + t, R[i] = 3e18;
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        if (x[i] < i) {
            puts("No");
            return 0;
        }
        if (x[i] != i) {
            c[i + 1]++, c[x[i] + 1]--;
            if (x[i] + 1 <= n) chkMin(R[x[i]], a[x[i] + 1] + t - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        if (c[i]) chkMax(L[i - 1], a[i] + t);
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1 && L[i] == L[i - 1]) L[i]++;
        if (L[i] > R[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) printf("%lld ", L[i]);
    return 0;
}