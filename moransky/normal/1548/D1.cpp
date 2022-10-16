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

const int N = 6005;

int n, x[N], y[N];

LL ans;

int cnt[2][2];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void inline work(int u) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        int dx = abs(x[i] - x[u]), dy = abs(y[i] - y[u]);
        int ox = dx % 4 == 2, oy = dy % 4 == 2;
        cnt[ox][oy]++;
    }
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 1; y++) {
            for (int u = 0; u <= 1; u++) {
                for (int v = 0; v <= 1; v++) {
                    int w = (gcd(x * 2, y * 2) + gcd(u * 2, v * 2) + gcd(abs(x * 2 - u * 2), abs(y * 2 - v * 2)));
                    if (w % 4 == 0) {
                        if (x == u && y == v) ans += cnt[x][y] * (cnt[x][y] - 1);
                        else ans += cnt[x][y] * cnt[u][v];
                    }
                }
            }
        }
    }
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    for (int i = 1; i <= n; i++) work(i);
    ans /= 6;
    printf("%lld\n", ans);
    return 0;
}