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

const int N = 2022;

int n, a[N], pos[N], d[N * 5], t;

void rev(int p) {
    d[++t] = p;
    reverse(a + 1, a + 1 + p);
    for (int i = 1; i <= n; i++) pos[a[i]] = i;
}

void inline solve(int n) {
    if (n == 1) return ;
    rev(pos[n]);
    rev(pos[n - 1] - 1);
    rev(pos[n - 1] + 1);
    rev(3);
    rev(n);
    solve(n - 2);
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n); t = 0;
        bool o = 1;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            pos[a[i]] = i;
            if ((a[i] & 1) != (i & 1)) o = 0;
        }
        if (!o) puts("-1");
        else {
            solve(n);
            printf("%d\n", t);
            for (int i = 1; i <= t; i++) printf("%d ", d[i]);
            puts("");
        }
    }
    return 0;
}