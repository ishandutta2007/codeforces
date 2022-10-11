#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    constexpr int N = 1 << 20;

    auto parity = [&](int n, int k) -> int {
        if (k > n) return 0;
        k = max(k, 0);
        if (n == 0) return 1;
        return k > 0 && ((n - 1) & (k - 1)) == k - 1;
    };

    vector<int> ans(N);
    for (int st = 0; st < n; st++) {
        int cur = a[st];
        for (int fn = st; fn < n; fn++) {
            if (fn != st) {
                if (a[fn] >= 21) break;
                if (cur * (1ll << a[fn]) >= N) break;
                cur *= 1 << a[fn];
            }

            int new_k = k - (st > 0) - (fn < n - 1);
            int left = max(0, st - 1) + max(0, n - 2 - fn);
            if (cur < N) ans[cur] ^= parity(left, new_k);
        }
    }

    int pos = N - 1;
    while (pos > 0 && ans[pos] == 0) pos--;
    while (pos != -1) cout << ans[pos--];
    cout << '\n';
}