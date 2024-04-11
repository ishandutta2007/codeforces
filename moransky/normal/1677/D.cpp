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

const int P = 998244353, N = 1e6 + 5;

int n, k, v[N], w[N];

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(k);
        for (int i = 1; i <= n; i++) read(v[i]);
        bool o = 1;
        int ans = 1;
        for (int i = n; i > n - k; i--) {
            if (v[i] != -1 && v[i] != 0) o = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (i - k <= 0) {
                ans = 1ll * ans * (i) % P;
                continue;
            }
            if (v[i - k] > 0) {
                if (v[i - k] + k >= i) {
                    o = 0;
                    break;
                }
            } else {
                int R = i - 1;
                if (v[i - k] == 0) chkMin(R, k);
                ans = 1ll * ans * (R + 1) % P;
            }
        }
        if (!o) puts("0");
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}