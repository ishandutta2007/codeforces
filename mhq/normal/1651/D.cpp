#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int x[maxN], y[maxN];
map<pair<int,int>,int> bad;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        bad[{x[i], y[i]}] = 1;
    }
    vector<pair<int,int>> all;
    for (int i = 1; i <= n; i++) {
        all.emplace_back(x[i], y[i]);
        for (int z = 0; z < 4; z++) {
            int nx = x[i] + dx[z];
            int ny = y[i] + dy[z];
            all.emplace_back(nx, ny);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    queue<int> q;
    vector<int> dist(all.size(), -1);
    vector<int> id(all.size(), -1);
    for (int t = 0; t < all.size(); t++) {
        for (int z = 0; z < 4; z++) {
            if (!bad.count(all[t])) {
                dist[t] = 0;
                id[t] = t;
                q.push(t);
            }
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int z = 0; z < 4; z++) {
            int nx = dx[z] + all[v].first;
            int ny = dy[z] + all[v].second;
            auto res = lower_bound(all.begin(), all.end(), make_pair(nx, ny)) - all.begin();
            if (res != all.size() && all[res] == make_pair(nx, ny)) {
                if (dist[res] == -1) {
                    dist[res] = dist[v] + 1;
                    id[res] = id[v];
                    q.push(res);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        auto res = lower_bound(all.begin(), all.end(), make_pair(x[i], y[i])) - all.begin();
        cout << all[id[res]].first << " " << all[id[res]].second << '\n';
    }
    return 0;
}