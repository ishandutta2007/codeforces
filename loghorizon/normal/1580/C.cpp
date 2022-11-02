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

const int N = 2e5 + 5, S = 500;

int n, m, x[N], y[N], B, s[N], c[N], ans, t[N];

int g[S][S];

void inline ins(int T, int i, int w) {
    int P = s[i];
    g[P][T % P] += -w;
    g[P][(T + x[i]) % P] += w;
}

void inline ins2(int T, int i, int w) {
    int P = s[i];
    for (int j = T; j <= m; j += P) {
        c[j] -= w;
        if (j + x[i] <= m) c[j + x[i]] += w;
    }
}
 
int main() {
    read(n), read(m);
    B = sqrt(m);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]), s[i] = x[i] + y[i];
    for (int i = 1; i <= m; i++) {
        int op, k; read(op), read(k);
        if (op == 1) {
            t[k] = i;
            ans++;
            if (s[k] <= B) {
                ins(i, k, 1);
            } else {
                ins2(i, k, 1);
            }
        } else {
            int p = (i - t[k] + s[k] - 1) / s[k];
            int T = t[k] + p * s[k];
            if (i > T - y[k]) ans--;
            if (s[k] <= B) {
                ins(T, k, -1);
            } else {
                if (T - y[k] >= i && T - y[k] <= m) c[T - y[k]]--;
                ins2(T, k, -1);
            }
            t[k] = 0;
        }

        ans += c[i];
        for (int j = 1; j <= B; j++) ans += g[j][i % j];
        printf("%d\n", ans);
    }
    return 0;
}