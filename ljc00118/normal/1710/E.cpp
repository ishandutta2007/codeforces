#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

ll sa[N], sb[N];
int a[N], b[N], cnta[N], cntb[N], nxta[N], nxtb[N];
int n, m, pa, pb;

int md;
ll calc(int x, int y, int opt) {
    ll ans = 0;
    if (cnta[x] >= y) ans += 1ll * x * y;
    else {
        int pos = nxta[y];
        ans += 1ll * pos * y + sa[x] - sa[pos];
    }
    if (y == m || cntb[y + 1] >= n - x) ans += 1ll * (n - x) * (m - y);
    else {
        int pos = nxtb[n - x];
        ans += 1ll * (m - pos + 1) * (n - x) + sb[y + 1] - sb[pos];
    }
    if (opt == 1) {
        if (pa <= x && pb <= y && a[pa] + b[pb] <= md) --ans;
        if (pa > x && pb > y && a[pa] + b[pb] > md) --ans;
    }
    return ans;
}

bool check(int mid) {
    md = mid;
    memset(nxta, 0, sizeof(nxta));
    for (int i = 0; i <= n; i++) nxtb[i] = m + 1;
    for (int i = 1, j = m; i <= n; i++) {
        while (j >= 1 && a[i] + b[j] > mid) --j;
        cnta[i] = j;
        sa[i] = sa[i - 1] + cnta[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = cnta[i]; j > cnta[i + 1]; j--) nxta[j] = i;
    }
    for (int i = m, j = 1; i >= 1; i--) {
        while (j <= n && b[i] + a[j] <= mid) ++j;
        cntb[i] = n + 1 - j;
        sb[i] = sb[i + 1] + cntb[i];
    }
    for (int i = m; i >= 1; i--) {
        for (int j = cntb[i]; j > cntb[i - 1]; j--) nxtb[j] = i;
    }
    ll ans1 = sb[1], ans2 = sb[1] - (a[pa] + b[pb] > mid);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < m && calc(i, j, 0) <= calc(i, j + 1, 0)) ++j;
        ans1 = max(ans1, calc(i, j, 0));
    }
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < m && calc(i, j, 1) <= calc(i, j + 1, 1)) ++j;
        ans2 = max(ans2, calc(i, j, 1));
    }
    return ans1 == ans2;
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= m; i++) read(b[i]);
    pa = a[1]; pb = b[1];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    pa = lower_bound(a + 1, a + n + 1, pa) - a;
    pb = lower_bound(b + 1, b + m + 1, pb) - b;
    int l = 0, r = a[pa] + b[pb], ans = r; --r;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    print(ans, '\n');
    return 0;
}