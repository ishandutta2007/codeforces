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

const int N = 1e5 + 5, MX = 448, INF = 1e9;

struct dsu {
    int f[N], val[N];

    void reset(int n) {
        for (int i = 1; i <= n + 1; i++) f[i] = i, val[i] = 0;
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void cover(int l, int r, int v) {
        l = find(l);
        while (l <= r) {
            val[l] = v;
            f[l] = l + 1;
            l = find(l);
        }
    }
} maxr[MX];

int a[N], b[MX], nxt[N], tax[MX];
int T, n, ans;

int main() {
    read(T);
    while (T--) {
        memset(tax, 0, sizeof(tax));
        memset(nxt, 0, sizeof(nxt));
        read(n);
        for (int i = 0; i < MX; i++) maxr[i].reset(n);
        for (int i = 1; i <= n; i++) read(a[i]), nxt[a[i]] = i;
        for (int i = 100000; i >= 1; i--) {
            if (!nxt[i]) {
                nxt[i] = nxt[i + 1];
            }
        }
        for (int i = n; i >= 1; i--) {
            int mx;
            for (int j = 0; ; j++) {
                b[j] = maxr[j].val[i];
                if (!b[j]) {
                    mx = j;
                    break;
                }
            }
            tax[mx] = 1;
            int minn = INF;
            for (int j = 0; j <= mx; j++) {
                int mi = min(minn, b[j]);
                int l = a[i] * 2 - minn + 1, r = a[i] * 2 - mi + 1;
                l = nxt[max(1, l)];
                if (j == mx) r = i - 1;
                else r = min(i - 1, nxt[max(1, r)] - 1);
                if (l <= r) maxr[j].cover(l, r, a[i]);
                minn = mi;
            }
        }
        for (int i = 0; ; i++) {
            if (!tax[i]) {
                ans ^= i;
                break;
            }
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}