#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const long long INF = (long long) 1e10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(6);
    for (auto &x : a) {
        cin >> x;
    }

    int n;
    cin >> n;
    vector<pair<long long, int>> events;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 6; j++) {
            events.emplace_back(x - a[j], i);
        }
    }
    sort(all(events));

    vector<long long> where(n, -1);
    set<pair<long long, int>> last;

    long long ans = INF;
    for (auto [x, index] : events) {
        if (where[index] != -1) {
            last.erase({ where[index], index });
        }
        last.insert({ x, index });
        where[index] = x;

        if (sz(last) == n) {
            ans = min(ans, x - last.begin()->first);
        }
    }

    cout << ans << '\n';
}