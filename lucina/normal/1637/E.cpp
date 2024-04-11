#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int n, m;
vector <int> f[1024];

void solve() {
    cin >> n >> m;
    map <int, int> cnt;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    vector <int> com;
    for (auto &[u, v] : cnt) {
        com.push_back(v);
    }
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    for (auto &[x, ct] : cnt) {
        int id = lower_bound(com.begin(), com.end(), ct) - com.begin();
        f[id].push_back(x);
    }
    n = com.size();
    for (int i = 0 ; i < n ; ++ i) reverse(f[i].begin(), f[i].end());

    vector <pair <int, int>> ban(m);
    for (auto &[u, v] : ban)
        cin >> u >> v;
    sort(ban.begin(), ban.end());

    auto is_ban = [&](int x, int y) {
        pair <int, int> s = minmax(x, y);
        return binary_search(ban.begin(), ban.end(), s);
    };
    int64_t ans = 0;

    for (int i = 0 ; i < n ; ++ i)
    for (int j = i + 1 ; j < n ; ++ j) {
        int64_t base = com[i] + com[j];
        vector <int> &x = (f[i].size() < f[j].size() ? f[i] : f[j]);
        vector <int> &y = (f[i].size() < f[j].size() ? f[j] : f[i]);

        for (int k = 0 ; k < x.size() ; ++ k) {
            int ptr = 0;
            while (ptr < y.size() && is_ban(x[k], y[ptr]))
                ptr ++;
            if (ptr < y.size()) {
                ans = max(ans, base * (x[k] + y[ptr]));
            }
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        vector <int> &x = f[i];
        int64_t base = 2 * com[i];
        for (int k = 0 ; k < x.size() ; ++ k) {
            int j = 0;
            while (j < k && is_ban(x[k], x[j]))
                j ++;
            if (j < k)
                ans = max(ans, base * (x[k] + x[j]));
        }
    }
    cout << ans << '\n';

    for (int i = 0 ; i < 1024 ; ++ i)
        f[i].clear();
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}