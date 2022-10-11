#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MOD = 998244353;

int n, k, x[N], y[N];
long long off = 0, ret = 0, ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    x[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> k;
        int pos = lower_bound(x + 1, x + i + 1, y[i]) - x;
        long long cur = (x[pos] - y[i] + (pos == i ? 1 : ans[pos] + off + x[i] - x[i - 1])) % MOD;
        (off += x[i] - (x[i - 1] + 1) + cur) %= MOD;
        ans[i] = (cur + MOD - off) % MOD;
        (ret += x[i] - x[i - 1] - k + cur * k) %= MOD;
    }
    cout << ret;
}