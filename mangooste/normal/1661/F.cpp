#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0, last = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x - last;
        last = x;
    }

    ll max_cost;
    cin >> max_cost;

    auto solve = [&](int length, int cnt) {
        cnt++;
        int base = length / cnt, rem = length % cnt;
        return 1ll * base * base * (cnt - rem) + 1ll * (base + 1) * (base + 1) * rem;
    };
    
    auto when = [&](int i, ll value) {
        int l = -1, r = a[i] - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            (solve(a[i], mid) - solve(a[i], mid + 1) < value ? r : l) = mid;
        }
        return r;
    };

    vector<int> event(n);

    auto fill_event = [&](ll value) {
        for (int i = 0; i < n; i++) {
            event[i] = when(i, value);
        }
    };

    ll l = -1, r = 2e18;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        fill_event(mid);
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            cost += solve(a[i], event[i]);
            if (cost > max_cost) break;
        }
        (cost > max_cost ? r : l) = mid;
    }

    fill_event(r);
    ll cost_left = max_cost;
    for (int i = 0; i < n; i++) {
        cost_left -= solve(a[i], event[i]);
    }
    cout << accumulate(all(event), 0) + (-min(0ll, cost_left) + l - 1) / l << '\n';
}