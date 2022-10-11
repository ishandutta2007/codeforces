#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    map<int, int> first, last, freq;
    for (int i = 0; i < n; i++) {
        if (first.find(a[i]) == first.end())
            first[a[i]] = i;
        last[a[i]] = i;
        freq[a[i]]++;
    }

    vector<vector<pair<int, int>>> events(n + 1);
    for (auto [x, pos] : first)
        events[pos].emplace_back(x, 0);
    for (auto [x, pos] : last)
        events[pos].emplace_back(x, 1);

    multiset<int> open;
    set<int> mxs;
    int ans = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        for (auto [x, type] : events[i])
            if (!type) {
                open.insert(freq[x]);
                mxs.insert(freq[x]);
            } else
                open.erase(open.find(freq[x]));

        if (open.empty()) {
            ans += i - prev - *mxs.rbegin();
            prev = i;
            mxs.clear();
        }
    }
    cout << ans << '\n';
}