// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y >= x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e4 + 5;

int n, a[N], x, f[N], L[N], g[N], q[N];
 
LL s[N], v[N];

int inline get(int x) {
    if (x < 0) return 0;
    return f[x];
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
        read(x);
        for (int i = 1; i <= n; i++) v[i] = s[i] - 1ll * x * i;
        int p = 0;
        LL mx = 0;
        int hh = 1, tt = 0;
        for (int i = 1; i <= n; i++) {
            if (i > 1 && v[q[hh]] > v[i]) {
                int l = hh, r = tt;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (v[q[mid]] > v[i]) l = mid;
                    else r = mid - 1;
                }
                L[i] = q[r];
            } else L[i] = -1;
            while (hh <= tt && v[q[tt]] <= v[i - 1]) tt--;
            q[++tt] = i - 1;
       }
        for (int i = 0; i <= n; i++) f[i] = g[i] = 0;
        hh = 0, tt = 0;
        for (int i = 1, j = -1; i <= n; i++) {
            chkMax(j, L[i]);
            while (hh <= tt && q[hh] <= j) hh++;
            if (hh <= tt) chkMax(f[i], g[q[hh]] + i - q[hh]);
            chkMax(g[i], max(g[i - 1], f[i - 1]));
            while (hh <= tt && g[q[tt]] - q[tt] < g[i] - i) tt--;
            q[++tt] = i;
        }
        printf("%d\n", max(f[n], g[n]));
    }
    return 0;
}