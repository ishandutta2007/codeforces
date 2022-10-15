#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

struct sequence {
    vector<pair<int, ll>> data;

    sequence() = default;

    sequence(const vector<int> &a, int m) { for (int x: a) { add(x, 1, m); }}

    void add(int x, ll copies, int m) {
        if (x % m == 0) add(x / m, copies * m, m); else data.emplace_back(x, copies);
    }
};

bool equal(sequence as, sequence bs) {
    auto &a = as.data;
    auto &b = bs.data;
    for (int i = 0, j = 0; i < a.size() || j < b.size();) {
        if ((i == a.size()) ^ (j == b.size())) return false;
        if (a[i].first != b[j].first) return false;
        ll min = std::min(a[i].second, b[j].second);
        a[i].second -= min; b[j].second -= min;
        if (a[i].second == 0) i++;
        if (b[j].second == 0) j++;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int k;
    cin >> k;
    vector<int> b(k);
    for (int &x: b) cin >> x;
    cout << (equal(sequence(a, m), sequence(b, m)) ? "Yes" : "No") << '\n';
}