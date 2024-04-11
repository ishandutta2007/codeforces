#include <bits/stdc++.h>
using namespace std;

int n, u;
map<int, int> ma;
priority_queue<pair<int, int>> pq;
vector<array<int, 3>> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> u;
        ma[u]++;
    }
    for (auto [u, l] : ma) {
        pq.push({l, u});
    }
    while (pq.size() >= 3) {
        auto [bc, br] = pq.top(); pq.pop();
        auto [mc, mr] = pq.top(); pq.pop();
        auto [sc, sr] = pq.top(); pq.pop();
        ans.push_back({br, mr, sr});
        if (--bc > 0) {
            pq.push({bc, br});
        }
        if (--mc > 0) {
            pq.push({mc, mr});
        }
        if (--sc > 0) {
            pq.push({sc, sr});
        }
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
        sort(v.begin(), v.end(), greater<int>());
        cout << v[0] << " " << v[1] << " " << v[2] << '\n';
    }
}