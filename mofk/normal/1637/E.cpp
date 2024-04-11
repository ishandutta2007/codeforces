#include <bits/stdc++.h>

using namespace std;

int main(void) {
    mt19937 rng(1007050321);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        map<int, int> f;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++f[x];
        }
        set<pair<int, int>> bad;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            bad.insert({x, y});
            bad.insert({y, x});
        }
        map<int, vector<int>> buck;
        vector<pair<int, int>> all;
        for (auto x: f) {
            buck[x.second].push_back(x.first);
            all.push_back(x);
        }
        shuffle(all.begin(), all.end(), rng);
        long long ans = 0;
        for (auto item: all) {
            int x = item.first, cx = item.second;
            for (auto it = buck.begin(); it != buck.end(); ++it) {
                long long cy = cx + it->first;
                for (int i = it->second.size() - 1; i >= 0; --i) {
                    if (cy * (x + it->second[i]) <= ans) break;
                    if (x == it->second[i] || bad.find({x, it->second[i]}) != bad.end()) continue;
                    ans = cy * (x + it->second[i]);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}