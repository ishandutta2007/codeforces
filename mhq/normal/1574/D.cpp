#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 12;
vector<int> vals[maxN];
int c[maxN];
ll best = -1e18;
vector<vector<int>> all;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        vals[i].resize(c[i]);
        for (int& x : vals[i]) {
            cin >> x;
        }
    }
    int m;
    cin >> m;
    all.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int z = 0; z < all[i].size(); z++) {
            cin >> all[i][z];
            all[i][z]--;
        }
    }
    sort(all.begin(), all.end());
    vector<int> cur(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cur[i] = c[i] - 1;
        s += vals[i][cur[i]];
    }
    priority_queue<pair<int,pair<int,vector<int>>>> pq;
    pq.push(make_pair(s, make_pair(0, cur)));
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int x = it.first;
        auto pos = it.second.first;
        auto cur = it.second.second;
        int p = lower_bound(all.begin(), all.end(), cur) - all.begin();
        if (p == (int)all.size() || all[p] != cur) {
            for (int x : cur) cout << x + 1 << " ";
            return 0;
        }
        else {
            if (cur[pos] > 0) {
                cur[pos]--;
                pq.push(make_pair(x - vals[pos][cur[pos] + 1] + vals[pos][cur[pos]], make_pair(pos, cur)));
                cur[pos]++;
            }
            if (pos + 1 < n) {
                pq.push(make_pair(x, make_pair(pos + 1, cur)));
            }
        }
    }
    return 0;
}