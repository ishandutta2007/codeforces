// Skyqwq
#include <bits/stdc++.h>

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

const int N = 105;

int a[N], n, t, d[N];

int inline ask() {
    printf("? ");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts(""); fflush(stdout);
    int x; read(x); return x;
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            t = n;
            break;
        }
        for (int j = 1; j < n; j++) a[j] = i + 1;
        a[n] = 1;
        if (!ask()) {
            t = i;
            break;
        }
    }
    d[n] = t;
    for (int i = 1; i <= n; i++) {
        if (i == t) continue;
        for (int j = 1; j < n; j++) a[j] = n - i + 1;
        a[n] = n - t + 1;
        d[ask()] = i;
    }
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
    puts(""); fflush(stdout);
    return 0;
}