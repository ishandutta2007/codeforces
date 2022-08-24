#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, d, m;
    cin >> n >> d >> m;
    vector < ll > good, bad;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (x > m) bad.emplace_back(x);
        else good.emplace_back(x);
    }
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());
//    reverse(good.begin(), good.end());
    reverse(bad.begin(), bad.end());
    vector < ll > pref_bad(bad.size() + 1);
    vector < ll > pref_good(good.size() + 1);
    for (int i = 0; i < bad.size(); i++) pref_bad[i + 1] = pref_bad[i] + bad[i];
    for (int i = 0; i < good.size(); i++) pref_good[i + 1] = pref_good[i] + good[i];
    ll best = 0;
    for (int cnt_bad = 0; cnt_bad <= bad.size(); cnt_bad++) {
        ll days_free = max(0LL, (1LL * cnt_bad - 1) * d);
        if (days_free + cnt_bad > n) continue;
        ll need_good = max(0LL, days_free - ((ll)bad.size() - cnt_bad));
        if (need_good > good.size()) continue;
        best = max(best, pref_bad[cnt_bad] + pref_good.back() - pref_good[need_good]);
    }
    cout << best << '\n';
    return 0;
}