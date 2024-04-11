#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN];
int n;
int pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int best = 0;
    vector < pair < int, int > > all;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        for (auto& it : all) {
            it.first = max(it.first, a[i]);
        }
        all.emplace_back(a[i], pref[i - 1]);
        sort(all.begin(), all.end());
        map < int, int > mp;
        for (auto& it : all) {
            if (!mp.count(it.first)) mp[it.first] = it.second;
            else mp[it.first] = min(mp[it.first], it.second);
        }
        all.clear();
        for (auto& it : mp) {
            all.emplace_back(it);
            best = max(best, pref[i] - it.second - it.first);
        }
    }
    cout << best;
    return 0;
}