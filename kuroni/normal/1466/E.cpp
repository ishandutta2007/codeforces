#include <bits/stdc++.h>
using namespace std;

const int N = 500005, LG = 60, MOD = 1E9 + 7;

int t, n, cnt[LG];
long long a[N], pw[LG];

void init() {
    pw[0] = 1;
    for (int i = 1; i < LG; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
}

void solve() {
    cin >> n;
    fill(cnt, cnt + LG, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < LG; j++) {
            cnt[j] += (a[i] >> j & 1);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long ov = 0, av = 0;
        for (int j = 0; j < LG; j++) {
            if (a[i] >> j & 1) {
                (ov += pw[j] * n) %= MOD;
                (av += pw[j] * cnt[j]) %= MOD;
            } else {
                (ov += pw[j] * cnt[j]) %= MOD;
            }
        }
        (ans += ov * av) %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) {
        solve();
    }
}