#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
const int INF = 2 * (int)1e9;
set < pair < int, int > > fr;
int a[maxN], t[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    fr.insert({1, INF});
    cin >> n;
    vector < pair < int, int > > all(n);
    for (int i = 0; i < n; i++) {
        cin >> all[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> all[i].first;
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    ll ans = 0;
    for (auto it : all) {
        int cost = it.first;
        int where = it.second;
        auto ptr = fr.lower_bound({where, -1});
        if (ptr != fr.begin()) {
            auto gg = *prev(ptr);
            if (gg.first <= where && where <= gg.second) {
                fr.erase(gg);
                if (gg.first <= where - 1) fr.insert({gg.first, where - 1});
                if (where + 1 <= gg.second) fr.insert({where + 1, gg.second});
                continue;
            }
        }
        auto gg = *ptr;
        ans += 1LL * cost * (gg.first - where);
        fr.erase(gg);
        if (gg.first + 1 <= gg.second) fr.insert({gg.first + 1, gg.second});
    }
    cout << ans;
    return 0;
}