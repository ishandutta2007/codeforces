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

const int N = 5005;

int n, p[N], pr[N][N], sf[N][N];

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(p[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) pr[i][j] = pr[i - 1][j];
            for (int j = p[i]; j <= n; j++) pr[i][j]++;
        }
        for (int i = n; i; i--) {
            for (int j = 1; j <= n; j++) sf[i][j] = sf[i + 1][j];
            for (int j = p[i]; j <= n; j++) sf[i][j]++;
        }
        LL ans = 0;
        for (int b = 2; b < n; b++) {
            for (int c = b + 1; c < n; c++) {
                ans += pr[b - 1][p[c] - 1] * sf[c + 1][p[b] - 1];
             }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                pr[i][j] = sf[i][j] = 0;
            }
        }
    }
    return 0;
}