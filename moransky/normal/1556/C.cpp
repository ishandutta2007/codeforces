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

const int N = 1005;

int n, c[N];
 
LL s[N];

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(c[i]);
        if (i & 1) s[i] = s[i - 1] + c[i];
        else s[i] = s[i - 1] - c[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; i += 2) {
        LL L = s[i - 1], R = s[i] - 1, k = 1e18;
        for (int j = i + 1; j <= n; j++) {
            if (j % 2 == 0) {
                LL x = s[j], y = s[j - 1] - 1;
                LL nx = max(L, x), ny = min(min(y, R), k);
                if (nx <= ny) ans += ny - nx + 1;
                chkMin(k, s[j]); 
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}