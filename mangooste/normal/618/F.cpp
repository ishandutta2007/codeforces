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
    for (auto &x : a) cin >> x;
    vector<int> b(n);
    for (auto &x : b) cin >> x;

    multiset<pair<ll, int>> can_a, can_b;
    vector<bool> ans_a(n, true), ans_b(n, true);
    for (int i = 0; i < n; i++) {
        can_a.emplace(a[i], i);
        can_b.emplace(b[i], i);
    }
    bool swapped = false;
    ll sum_a = accumulate(all(a), 0ll), sum_b = accumulate(all(b), 0ll);
    while (sum_a != sum_b) {
        if (sum_a < sum_b) {
            swap(sum_a, sum_b);
            swap(can_a, can_b);
            swap(ans_a, ans_b);
            swapped ^= 1;
        }

        ll delta = sum_a - sum_b;
        auto it = can_a.lower_bound({delta, -1});
        if (it == can_a.end()) it--;
        sum_a -= it->first;
        ans_a[it->second] = false;
        can_a.erase(it);
    }

    if (swapped) swap(ans_a, ans_b);
    assert(!ans_a.empty() && !ans_b.empty());
    for (auto v : {ans_a, ans_b}) {
        cout << count(all(v), true) << '\n';
        for (int i = 0; i < n; i++) {
            if (v[i]) cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}