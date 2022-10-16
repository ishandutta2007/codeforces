#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m;
int p[1000006];
int b[1005], e[1005];
int lst[1000006], nxt[1000006];
int rmq[1005][1005];
int f[1005][1005];
bool g[1005][1005];

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int dp(int l, int r) {
    if (g[l][r]) return f[l][r];
    g[l][r] = 1;
    int &ret = f[l][r];
    if (l > r) return ret = 1;
    int id = rmq[l][r];
    if (b[id] < l || e[id] > r) return ret = 0;
    int lft = 0, rht = 0, mid = 1;
    for (int i = l - 1; i < b[id]; ++i) add(lft, 1ll * dp(l, i) * dp(i + 1, b[id] - 1) % mod);
    for (int i = r + 1; i > e[id]; --i) add(rht, 1ll * dp(i, r) * dp(e[id] + 1, i - 1) % mod);
    int pre = b[id] + 1;
    for (int i = b[id]; i <= e[id]; ++i) {
        if (p[i] == id) {
            mid = 1ll * mid * dp(pre, i - 1) % mod;
            pre = i + 1;
        }
    }
    ret = 1ll * lft * rht % mod;
    ret = 1ll * ret * mid % mod;
    //cout << l << ' ' << r << ' ' << id << ' ' << lft << ' ' << rht << ' ' << mid << ' ' << ret << endl;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
        if (p[i] == p[i-1]) --i, --m;
    }
    p[m+1] = 0;
    for (int i = 1; i <= m; ++i) e[p[i]] = i;
    for (int i = m; i >= 1; --i) b[p[i]] = i;
    for (int i = 1; i <= m; ++i) {
        lst[i] = i - 1;
        while (p[lst[i]] >= p[i]) lst[i] = lst[lst[i]];
    }
    nxt[m+1] = m + 1;
    for (int i = m; i >= 1; --i) {
        nxt[i] = i + 1;
        while (p[nxt[i]] >= p[i]) nxt[i] = nxt[nxt[i]];
    }
    for (int i = 1; i <= n; ++i) if (nxt[b[i]] <= e[i] || lst[e[i]] >= b[i])
        return cout << 0 << endl, 0;
    assert(m < 2 * n);
    for (int i = 1; i <= m; ++i) {
        rmq[i][i] = p[i];
        for (int j = i + 1; j <= m; ++j) rmq[i][j] = min(rmq[i][j-1], p[j]);
    }
    cout << dp(1, m) << endl;
    return 0;
}