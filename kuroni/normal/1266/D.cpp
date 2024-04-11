#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5;

int n, m, u, v, w;
long long pro[N];
set<pair<long long, int>> se;
vector<pair<pair<int, int>, long long>> ans;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        pro[u] -= w;
        pro[v] += w;
    }
    for (int i = 1; i <= n; i++) {
        se.insert({pro[i], i});
    }
    while (!se.empty() && se.begin()->fi != 0) {
        int u = se.begin()->se, v = prev(se.end())->se;
        long long w1 = se.begin()->fi, w2 = prev(se.end())->fi;
        long long tmp = min(abs(w1), abs(w2));
        // cout << u << " " << v << " " << w1 << " " << w2 << " " << tmp << '\n';
        se.erase(se.begin()); se.erase(prev(se.end()));
        ans.push_back({{u, v}, tmp});
        se.insert({w1 + tmp, u});
        se.insert({w2 - tmp, v});
    }
    cout << ans.size() << '\n';
    for (pair<pair<int, int>, long long> &v : ans) {
        cout << v.fi.fi << " " << v.fi.se << " " << v.se << '\n';
    }
}