/*
    16.11.2018 22:05:05
*/

#include <bits/stdc++.h>

using namespace std;

vector< long long > tree;
vector< long long > a;
int n, k, x;

void build() {
    tree.assign(4 * k, -1);
    // if (l == r) {
    //     tree[i] = a[i];
    //     return;
    // }
    // int m = (l + r) / 2;
    // build(2 * i + 1, l, m);
    // build(2 * i + 2, m + 1, r);
    // tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

long long ask() {
    return tree[0];
}

void change(int ind, long long u) {
    int l = 0, r = k - 1, i = 0;
    while (r > l) {
        int m = (l + r) >> 1;
        i = 2 * i + 1;
        if (m >= ind) {
            r = m;
        } else {
            l = m + 1;
            ++i;
        }
    }
    tree[i] = u;
    while (i > 0) {
        i = (i - 1) >> 1;
        long long mx = max(tree[2 * i + 1], tree[2 * i + 2]);
        if (mx == tree[i]) {
            return;
        }
        tree[i] = mx;
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k >> x;
    // if (x * k + k - 1 < n) {
    //     cout << -1 << '\n';
    //     return 0;
    // }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // dp[i][j] = max_{i - k <= i1 < i} dp[i1][j - 1]
    build();
    vector< long long > dpOld(n, -1), dpNew(n, -1);
    for (int i = 0; i < k; ++i) {
        dpOld[i] = a[i];
    }
    for (int i = 1; i < x; ++i) {
        // int ind = 0;
        for (int j = 0; j < n; ++j) {
            long long u = ask();
            if (u != -1) {
                dpNew[j] = a[j] + u;
            } else {
                dpNew[j] = -1;
            }
            change(j % k, dpOld[j]);
            // print(tree);
            // ++ind;
            // if (ind == k) {
            //     ind = 0;
            // }
        }
        // print(dpOld);
        // print(dpNew);
        // cout << '\n';
        swap(dpOld, dpNew);
        build();
    }
    long long ans = -1;
    for (int i = max(0, n - k); i < n; ++i) {
        ans = max(ans, dpOld[i]);
    }
    cout << ans << '\n';
    // vector< map< long long, int > > mx(x - 1);
    // vector< vector< long long > > dp(n, vector< long long >(x, -1));
    // dp[0][0] = a[0];
    // for (int i = 0; i < x - 1; ++i) {
    //     mx[i][-dp[0][i]] = 1;
    // }
    // // print(mx);
    // // mx[0].insert(5);
    // // mx[0].insert(6);
    // // print(mx);
    // // mx[0].erase(mx[0].find(5));
    // // print(mx);
    // // return 0;
    // for (int i = 1; i < n; ++i) {
    //     if (i + 1 > k) {
    //         dp[i][0] = -1;
    //     } else {
    //         dp[i][0] = a[i];
    //     }
    //     // cout << "mx = ";
    //     // print(mx);
    //     for (int j = 1; j < x; ++j) {
    //         if (mx[j - 1].begin()->first != 1) {
    //             dp[i][j] = a[i] - mx[j - 1].begin()->first;
    //         }
    //     }
    //     for (int j = 0; j < x - 1; ++j) {
    //         ++mx[j][-dp[i][j]];
    //         // cout << "j = " << j << endl;
    //         // cout << "mx = ";
    //         // print(mx);
    //         // cout << "dp = ";
    //         // print(dp);
    //         if (i >= k) {
    //             --mx[j][-dp[i - k][j]];
    //             if (mx[j][-dp[i - k][j]] == 0) {
    //                 mx[j].erase(-dp[i - k][j]);
    //             }
    //             // cout << "deleted dp[" << i - k << "][" << j << "]: " << dp[i - k][j] << endl;
    //         }
    //     }
    //     // print(dp);
    //     // print(mx);
    // }
    // long long ans = -1;
    // for (int i = max(0, n - k); i < n; ++i) {
    //     ans = max(ans, dp[i][x - 1]);
    // }
    // cout << ans << '\n';
    return 0;
}