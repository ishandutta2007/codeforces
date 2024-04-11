// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, q, P, a[N], f[N], g[N], b[N], cnt = 0;
 
char op[5];

int inline get(int x) {
    int r = (g[x] - g[x - 1] + P) % P;
    if (x >= 2) r = (r - g[x - 2] + P) % P;
    return r;
}

void inline chg(int x) {
    if (!b[x]) cnt--;
    b[x] = (b[x] + get(x)) % P;
    if (!b[x]) cnt++;
}

int main() {
    read(n), read(q), read(P);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        int x; read(x);
        a[i] = (a[i] - x + P) % P;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = (a[i] - a[i - 1] + P) % P;
        if (i >= 2) b[i] = (b[i] - a[i - 2] + P) % P;
        if (!b[i]) cnt++;
    }
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % P;
    }
    while (q--) {
        scanf("%s", op); int l, r; read(l), read(r);
        int z = r - l + 1;
        if (op[0] == 'A') {
            g[l] = f[1], g[r] = f[z];
            if (l < r) g[l + 1] = f[2], g[r - 1] = f[z - 1];
        } else {
            g[l] = P - f[1], g[r] = P - f[z];
            if (l < r) g[l + 1] = P - f[2], g[r - 1] = P - f[z - 1];
        }
        chg(l);
        if (l < r) {
            chg(l + 1);
        }
        if (r < n) {
            chg(r + 1);
        }
        if (r + 1 < n) {
            chg(r + 2);
        }
        g[l] = g[r] = g[l + 1] = g[r - 1] = 0;
        puts(cnt == n ? "YES" : "NO");
    }
    return 0;
}