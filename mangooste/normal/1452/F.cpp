#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> cnt(n);
    for (auto &x : cnt)
        cin >> x;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, new_value;
            cin >> pos >> new_value;
            cnt[pos] = new_value;
        } else {
            int x;
            ll k;
            cin >> x >> k;

            for (int i = 0; i <= x; i++)
                k -= cnt[i];
            k = max(k, 0ll);

            ll small_operations = 0;
            for (int i = 0; i <= x; i++)
                small_operations += cnt[i] * ((1ll << i) - 1);

            ll ans = 0;
            ll best = LLONG_MAX;
            if (k <= small_operations)
                best = min(best, k);

            for (int i = x + 1; i < n && k; i++) {
                ll can_take = k / (1ll << (i - x));
                ll new_small = min<ll>(can_take, cnt[i]) * (1ll << (i - x));

                k -= new_small;
                small_operations += new_small * ((1ll << x) - 1);
                ans += min<ll>(can_take, cnt[i]) * ((1ll << (i - x)) - 1);
                if (can_take >= cnt[i])
                    continue;

                for (int j = i; j > x; j--) {
                    if (k <= small_operations)
                        best = min(best, ans + k);

                    if ((1ll << (j - x)) < k) {
                        small_operations += (1ll << (j - x)) * ((1ll << x) - 1);
                        k -= (1ll << (j - x));
                        ans += (1ll << (j - x)) - 1;
                    }

                    if (k <= small_operations)
                        best = min(best, ans + k);

                    ans++;
                    if (j == x + 1) {
                        k -= min(k, 2ll);
                        if (k == 0)
                            best = min(best, ans);
                        small_operations += (1ll << x) - 1;
                    }
                }
                assert(!k);
                break;
            }

            if (k <= small_operations)
                best = min(best, ans + k);

            if (best == LLONG_MAX)
                best = -1;
            cout << best << '\n';
        }
    }
}