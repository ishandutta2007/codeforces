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

const int N = 2e5 + 5, INF = 1e9, S = 18;

int n, a[N], L[N], R[N], pr[N], sf[N], pos[N], X[N], Y[N], s[N], top, nt;

int de[N], inc[N];

int inline cmp(int x, int y) {
    return a[x] > a[y] ? x : y;
}

struct ST{
    int f[N][S], g[N];
    void inline STPrework() {
        g[0] = -1;
        for (int i = 1; i <= n; i++) 
            f[i][0] = i, g[i] = g[i >> 1] + 1;
        for (int j = 1; j <= g[n]; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                f[i][j] = cmp(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }

    int inline query(int l, int r) {
        int k = g[r - l + 1];
        return cmp(f[l][k], f[r - (1 << k) + 1][k]);
    }
} st;

int getMax(int l, int r) {
    assert(l <= r);
    return st.query(l, r);
}



bool inline chk2(int l, int r, int o) {
    if (l == r) {
        nt = a[r];
        return 1;
    }
    int x = min(de[l], r), y = max(inc[r], l);
    assert(x <= y);
    int p = getMax(x, y);
    x = max(X[p], l), y = min(Y[p], r);
    nt = 0;
    if (x == y) {
        nt = p > l && a[x] >= o ? a[p - 1] : a[p];
        return r == x || a[x + 1] > o;
    } else {
        assert(x < p && p < y);
        assert(a[p] > a[p - 1] && a[p] > a[p + 1]);
        bool ok = 0;
        if (L[p] <= x && pr[p] > o && de[p + 1] >= y) {
            ok = 1;
            chkMax(nt, a[y]);
        }
        if (R[p] >= y && inc[p - 1] <= x && a[x] > o) {
            ok = 1;
            chkMax(nt, sf[p]);
        }
        return ok;
    }
}


bool inline chk1(int l, int r, int o) {
    if (l == r) {
        nt = a[r];
        return 1;
    }
    int x = min(de[l], r), y = max(inc[r], l);
    assert(x <= y);
    int p = getMax(x, y);
    x = max(X[p], l), y = min(Y[p], r);
    nt = 0;
    if (x == y) {
        assert(x == p);
        nt = p == r || a[x] < o ? a[p] : a[p + 1];
        return l == x || a[x - 1] > o;
    } else {
        assert(x < p && p < y);
        assert(a[p] > a[p - 1] && a[p] > a[p + 1]);
        bool ok = 0;
        if (L[p] <= x && a[y] > o && de[p + 1] >= y) {
            ok = 1;
            chkMax(nt, pr[p]);
        }
        if (R[p] >= y && inc[p - 1] <= x && sf[p] > o) {
            ok = 1;
            chkMax(nt, a[x]);
        }
        return ok;
    }
}

bool inline chk(int l, int r) {
    if (l == r) {
        return 1;
    }
    int x = min(de[l], r), y = max(inc[r], l);
    int p = getMax(x, y);
    x = max(X[p], l), y = min(Y[p], r);
    if (x == y) {
        return 1;
    } else {
        assert(x < p && p < y);
        assert(a[p] > a[p - 1] && a[p] > a[p + 1]);
        bool ok = 0;
        if (L[p] <= x && de[p + 1] >= y) {
            ok = 1;
        }
        if (R[p] >= y && inc[p - 1] <= x) {
            ok = 1;
        }
        return ok;
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]] = i;
    st.STPrework();
    for (int i = 1; i <= n; i++) {
        inc[i] = i;
        if (i > 1 && a[i] > a[i - 1]) inc[i] = inc[i - 1];
    }
    for (int i = n; i; i--) {
        de[i] = i;
        if (i < n && a[i] > a[i + 1]) de[i] = de[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        while (top && a[s[top]] < a[i]) top--;
        X[i] = s[top] + 1;
        s[++top] = i;
    }
    top = 0;
    s[0] = n + 1;

    for (int i = n; i; i--) {
        while (top && a[s[top]] < a[i]) top--;
        Y[i] = s[top] - 1;
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        int u = pos[i];
        if (u > 1 && a[u] > a[u - 1]) {
            int l = u, r = Y[u];
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (chk2(u, mid, a[u - 1])) l = mid;
                else r = mid - 1;
            }
            chk2(u, r, a[u - 1]);
            R[u] = r;
            sf[u] = nt;
        }
        if (u < n && a[u] > a[u + 1]) {
            int l = X[u], r = u;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (chk1(mid, u, a[u + 1])) r = mid;
                else l = mid + 1;
            }
            chk1(r, u, a[u + 1]);
            L[u] = r;
            pr[u] = nt;
        }
    }

    LL ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (!chk(j, i)) j++;
        ans += i - j + 1;
    }
    printf("%lld\n", ans);
    return 0;
}