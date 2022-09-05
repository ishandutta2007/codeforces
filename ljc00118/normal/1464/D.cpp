#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, md = 1e9 + 7;

int a[N], vis[N], cnt[6];
int T, n;

int calc(int x, int y) {
    int ct = (x + y * 2) / 3;
    return ct + abs(ct - y);
}

int main() {
    read(T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        read(n);
        int fuck = 0;
        for (int i = 1; i <= n; i++) read(a[i]), vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int now = i, tot = 0;
                while (!vis[now]) {
                    vis[now] = 1;
                    ++tot;
                    now = a[now];
                }
                if (n % 3 == 0) {
                    if (tot >= 3) fuck += (tot - 1) / 3;
                    tot %= 3;
                } else if (n % 3 == 1) {
                    while (tot >= 5) tot -= 3, ++fuck;
                } else if (n % 3 == 2) {
                    if (tot >= 3) fuck += (tot - 1) / 3;
                    tot %= 3;
                }
                ++cnt[tot];
            }
        }
        if (n % 3 == 0) {
            int ct = (cnt[1] + cnt[2] * 2) / 3, ans = 1;
            for (int i = 1; i <= n / 3; i++) ans = 1ll * ans * 3 % md;
            printf("%d %d\n", ans, ct + abs(ct - cnt[2]) + fuck);
        }
        if (n % 3 == 2) {
            int ans = 2;
            for (int i = 1; i <= n / 3; i++) ans = 1ll * ans * 3 % md;
            if (!cnt[2]) {
                printf("%d %d\n", ans, 1 + cnt[1] / 3 * 2 + fuck);
            } else {
                --cnt[2];
                int ct = (cnt[1] + cnt[2] * 2) / 3;
                printf("%d %d\n", ans, ct + abs(ct - cnt[2]) + fuck);
            }
        }
        if (n % 3 == 1) {
            int ans = 4, res = 1e9;
            for (int i = 1; i <= n / 3 - 1; i++) ans = 1ll * ans * 3 % md;
            {
                if (cnt[4]) {
                    res = min(res, cnt[4] - 1 + calc(cnt[1] + cnt[4] - 1, cnt[2]));
                } else {
                    if (cnt[1] && cnt[3]) {
                        res = min(res, 1 + calc(cnt[1] - 1, cnt[2]));
                    }
                }
            }
            {
                cnt[1] += cnt[4];
                if (cnt[2] >= 2) {
                    res = min(res, calc(cnt[1], cnt[2] - 2) + cnt[4]);
                } else if (cnt[2] == 1) {
                    if (cnt[3]) res = min(res, (cnt[1] + 1) / 3 * 2 + 1 + cnt[4]);
                    if (cnt[1] >= 2) res = min(res, (cnt[1] - 2) / 3 * 2 + 1 + cnt[4]);
                } else if (cnt[2] == 0) {
                    if (cnt[1] >= 4) res = min(res, (cnt[1] - 4) / 3 * 2 + 2 + cnt[4]);
                    if (cnt[1] >= 1 && cnt[3] >= 1) res = min(res, (cnt[1] - 1) / 3 * 2 + 2 + cnt[4]);
                    if (cnt[3] >= 2) res = min(res, (cnt[1] + 2) / 3 * 2 + 2 + cnt[4]);
                }
            }
            printf("%d %d\n", ans, res + fuck);
        }
    }
    return 0;
}