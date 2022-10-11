#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = a[i] - pref[i];

    array<vector<pair<ll, int>>, 2> st;
    st.fill({{LLONG_MIN, n}});

    ll answer = 0;
    array<map<ll, vector<int>>, 2> freq;

    for (int i = n - 1; i >= 0; i--) {
        while (st[i & 1].back().first >= pref[i + 1])
            st[i & 1].pop_back();

        st[i & 1].emplace_back(pref[i + 1], i);
        freq[i & 1][pref[i + 1]].push_back(-i);

        int pos = n;
        for (int parity : {0, 1})
            pos = min(pos, prev(lower_bound(all(st[parity]), pair{parity == i % 2 ? -pref[i] : pref[i], -1}))->second);

        for (int parity : {0, 1}) {
            auto it = freq[parity].find(parity == i % 2 ? -pref[i] : pref[i]);
            if (it == freq[parity].end())
                continue;

            answer += it->second.end() - upper_bound(all(it->second), -pos);
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}