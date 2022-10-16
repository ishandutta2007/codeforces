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

const int N = 2e5 + 5, L = 18;

int n, Lg[N];

LL a[N], b[N], f[N][L];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

LL inline query(int l, int r) {
    int k = Lg[r - l + 1];
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i < n; i++) b[i] = abs(a[i + 1] - a[i]);
        --n;
        Lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            f[i][0] = b[i];
            Lg[i] = Lg[i >> 1] + 1;
        }
        for (int j = 1; j < L; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (b[i] > 1) {
                int l = 1, r = n - i + 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (query(i, i + mid - 1) > 1) l = mid;
                    else r = mid - 1;
                }
                chkMax(ans, r + 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}