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

const int N = 105, S = 10005;
const LL INF = 1e18;

int n, a[N], b[N], s[N];

LL ans, f[N][S];

int main() {
    int T; read(T);
    while (T--) {
        ans = 0;
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), ans += a[i] * a[i] * (n - 1);
        for (int i = 1; i <= n; i++) read(b[i]), ans += b[i] * b[i] * (n - 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] + b[i];
        LL w = INF;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < S; j++) {
                f[i][j] = INF;
            } 
        }
        f[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < S; j++) {
                if (f[i][j] == INF) continue;
                if (i == n) chkMin(w, f[i][j]);
                chkMin(f[i + 1][j + a[i + 1]], f[i][j] + j * a[i + 1] + (s[i] - j) * b[i + 1]);
                chkMin(f[i + 1][j + b[i + 1]], f[i][j] + j * b[i + 1] + (s[i] - j) * a[i + 1]);
            }
        }
        printf("%lld\n", ans + 2 * w);
    }
    return 0;
}