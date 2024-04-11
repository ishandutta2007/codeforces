#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int64_t> people(n);
    vector<int64_t> x(m);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<pair<int64_t,int64_t>> evt;
    for (int i = 0; i < n; i++) {
        int64_t pos = i * 100;
        auto it = lower_bound(x.begin(), x.end(), pos);
        int64_t dis = 1e9;
        if (it != x.end())
            dis = min(dis, *it - pos);
        if (it != x.begin())
            dis = min(dis, pos - *prev(it));
        if (dis != 0) {
            evt.emplace_back((pos - dis) * 2 + 1, people[i]);
            evt.emplace_back((pos + dis) * 2, -people[i]);
        }
    }
    sort(evt.begin(), evt.end());
    int64_t ans = 0, sum = 0;
    for (size_t i = 0, j; i < evt.size(); i = j) {
        for (j = i; j < evt.size(); j++) {
            if (evt[j].first != evt[i].first)
                break;
            sum += evt[j].second;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}