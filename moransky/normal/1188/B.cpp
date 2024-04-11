#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
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

const int N = 3e5 + 5;

int n, p, k, a[N], ans;

map<int, int> m;

int main() {
    read(n), read(p), read(k);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        int t = (1ll * a[i] * a[i] % p * a[i] % p * a[i] - 1ll * k * a[i] % p + p) % p; 
        ans += m[t]; m[t]++;
    }
    printf("%d\n", ans);
}