#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m;
int p[505];
int rmq[505][505];
int f[505][505];
bool g[505][505];

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int dp(int l, int r) {
    if (g[l][r]) return f[l][r];
    g[l][r] = 1;
    int &ret = f[l][r];
    if (l >= r) return ret = 1;
    int id = rmq[l][r];
    int lft = 0, rht = 0;
    for (int i = l - 1; i < id; ++i) add(lft, 1ll * dp(l, i) * dp(i + 1, id - 1) % mod);
    for (int i = r + 1; i > id; --i) add(rht, 1ll * dp(i, r) * dp(id + 1, i - 1) % mod);
    ret = 1ll * lft * rht % mod;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> p[i];
    for (int i = 1; i <= m; ++i) {
        rmq[i][i] = i;
        for (int j = i + 1; j <= m; ++j) {
            int x = rmq[i][j-1];
            if (p[x] < p[j]) rmq[i][j] = x; else rmq[i][j] = j;
        }
    }
    cout << dp(1, m) << endl;
    return 0;
}