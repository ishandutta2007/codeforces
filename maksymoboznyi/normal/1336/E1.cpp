#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int M = 998244353;

int n, m, a[N], p[N], gp[N];
vector<int> basis;

void add(int x) {
    for (auto y: basis)
        if ((x ^ y) < x)
            x ^= y;
    if (!x)
        return;
    for (auto &y: basis)
        if ((x ^ y) < y)
            y ^= x;
    basis.pb(x);
}

int q1 = 0, q2 = 1;
int used[40], dp[2][40][(1 << 16)];
vector<int> q;

signed main()
{
    cin >> n >> m;
    gp[0] = 1;
    for (int i = 1; i <= n; i++)
        gp[i] = gp[i - 1] * 2 % M, cin >> a[i], add(a[i]);
    if (basis.size() <= 20) {
        for (int msk = 0; msk < (1ll << basis.size()); msk++) {
            int ans = 0;
            for (int i = 0; i < basis.size(); i++)
                if ((msk >> i) & 1)
                    ans ^= basis[i];
            p[__builtin_popcountll(ans)] += gp[n - basis.size()];
            p[__builtin_popcountll(ans)] %= M;
        }
        for (int i = 0; i <= m; i++)
            cout << p[i] << ' ';
        return 0;
    }
    for (int i = 0; i < basis.size(); i++) {
        for (int j = m - 1; j >= 0; j--)
            if ((basis[i] >> j) & 1) {
                used[j] = 1;
                break;
            }
    }
    for (int i = 0; i < m; i++)
        if (!used[i])
            q.pb(i);
    dp[q1][0][0] = 1;
    for (int i = 1; i <= basis.size(); i++) {
        int add_mask = 0;
        int x = basis[i - 1];
        for (int j = 0; j < q.size(); j++)
            if ((x >> q[j]) & 1)
                add_mask ^= (1ll << j);
        //cout << x << ' ' << add_mask << endl;
        dp[q2][0][0] = 1;
        for (int j = 1; j <= i; j++)
            for (int msk = 0; msk < (1 << q.size()); msk++)
                dp[q2][j][msk] = (dp[q1][j][msk] + dp[q1][j - 1][msk ^ add_mask]);//, cout << i << ' ' << j << ' ' << msk << ' ' << dp[i][j][msk] << endl;
        swap(q1, q2);
    }

    for (int j = 0; j <= basis.size(); j++)
        for (int msk = 0; msk < (1 << q.size()); msk++)
            p[j + __builtin_popcountll(msk)] += dp[q1][j][msk], p[j + __builtin_popcountll(msk)] %= M;
    for (int i = 0; i <= m; i++)
        cout << p[i] * gp[n - basis.size()] % M << ' ';
    return 0;
}