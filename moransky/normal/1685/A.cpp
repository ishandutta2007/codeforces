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

const int N = 1e5 + 5;

int n, a[N], b[N], t;

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        sort(a + 1, a + 1 + n);
        t = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1) b[i] = a[++t];
        }
        for (int i = 1; i <= n; i++) if (i % 2 == 0) b[i] = a[++t];
        b[0] = b[n], b[n + 1] = b[1];
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (!((b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i + 1] && b[i] < b[i - 1]))) {
                ok = 0;
            }
        }
        puts(ok ? "YES" : "NO");
        if (ok) {
            for (int i = 1; i <= n; i++) printf("%d " , b[i]);
            puts("");
        }
    }
    return 0;
}