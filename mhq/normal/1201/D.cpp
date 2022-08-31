#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
set < int > b;
int n, m, k, q;
int r[maxN], c[maxN];
set < int > s;
vector < int > all[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        cin >> r[i] >> c[i];
        s.insert(r[i]);
        all[r[i]].push_back(c[i]);
    }
    s.insert(1);
    all[1].push_back(1);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    vector < pair < ll, int > > cands;
    ll best = 1e18;
    if (s.size() == 1) {
        sort(all[1].begin(), all[1].end());
        cout << all[1].back() - 1 << '\n';
        return 0;
    }
    for (int col : s) {
        sort(all[col].begin(), all[col].end());
        int le = all[col][0];
        int ri = all[col].back();
        vector < int > now;
        auto it1 = b.lower_bound(le);
        auto it2 = b.lower_bound(ri);
        if (it1 != b.end()) {
            now.push_back(*it1);
        }
        if (it1 != b.begin()) {
            --it1;
            now.push_back(*it1);
        }
        if (it2 != b.end()) {
            now.push_back(*it2);
        }
        if (it2 != b.begin()) {
            --it2;
            now.push_back(*it2);
        }
        sort(now.begin(), now.end());
        now.erase(unique(now.begin(), now.end()), now.end());
        if (col == 1) {
            for (int v : now) {
                cands.emplace_back(ri - le + abs(ri - v), v);
            }
            continue;
        }
        vector < ll > vals(now.size(), 1e18);
        bool en = (col == (*(--s.end())));
        for (int j = 0; j < now.size(); j++) {
            int to = now[j];
            for (auto it : cands) {
                int from = it.second;
                ll dp = it.first;
                ll ndp = min(dp + abs(from - le) + abs(le - ri), dp + abs(from - ri) + abs(le - ri));
                if (en) best = min(best, ndp);
                else {
                    vals[j] = min({vals[j], dp + abs(from - le) + abs(le - ri) + abs(ri - to), dp + abs(from - ri) + abs(le - ri) + abs(le - to)});
                }
            }
        }
        cands.clear();
        for (int j = 0; j < now.size(); j++) {
            cands.push_back(make_pair(vals[j], now[j]));
        }
    }
    cout << best + (*(--s.end())) - 1;
    return 0;
}