#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MOD = 998244353, INV = (MOD + 1) / 2;

int n;
long long cur, dp[N], val[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    val[0] = 1;
    for (int i = 1; i <= n; i++) {
        int b = i & 1;
        cur = val[b ^ 1] * INV % MOD;
        val[b] = (val[b] * INV % MOD * INV % MOD + cur) % MOD;
    }
    cout << cur;
}