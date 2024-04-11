#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int m, k;
    cin >> m >> k;
    vector a(k, vector<int>(m));
    vector<ll> sum(k), sum_sq(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            sum_sq[i] += 1ll * a[i][j] * a[i][j];
        }
    }

    map<ll, int> mp;
    for (int i = 0; i < k - 1; i++) {
        mp[sum[i + 1] - sum[i]]++;
    }
    pair<ll, int> best = *mp.begin();
    for (auto p : mp) {
        if (p.second > best.second) best = p;
    }
    ll delta_sum = best.first;

    int p = 0;
    while (sum[p + 1] - sum[p] != delta_sum || sum[p + 2] - sum[p + 1] != delta_sum) {
        p++;
    }

    int where = 1;
    while (sum[where] - sum[where - 1] == delta_sum) {
        where++;
    }

    ll sum_v_sq = (sum_sq[p] + sum_sq[p + 2] - 2 * sum_sq[p + 1]) / 2;
    ll sum_xv = (sum_sq[p + 1] - sum_sq[0] - (p + 1) * (p + 1) * sum_v_sq) / (2 * (p + 1));

    ll need_sum = sum[where - 1] + delta_sum;
    ll need_sum_sq = sum_sq[0] + where * where * sum_v_sq + 2 * where * sum_xv;
    ll delta = -sum[where] + need_sum;

    for (int i = 0; i < m; i++) {
        if (need_sum_sq == sum_sq[where] + 2 * delta * a[where][i] + delta * delta) {
            cout << where << ' ' << a[where][i] + delta << '\n';
            return 0;
        }
    }
    assert(false);
}