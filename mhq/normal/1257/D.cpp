#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n;
        vector < int > a(n);
        for (int& v : a) cin >> v;
        cin >> m;
        vector < pair < int, int > > ev(m);
        for (auto& it : ev) cin >> it.first >> it.second;
        sort(ev.begin(), ev.end());
        vector < int > pref_max(m + 1);
        for (int i = m - 1; i >= 0; i--) {
            pref_max[i] = max(pref_max[i + 1], ev[i].second);
        }
        int mx = 0;
        for (int i = 0; i < a.size(); i++) mx = max(mx, a[i]);
        if (mx > ev.back().first) {
            cout << -1 << '\n';
            continue;
        }
        reverse(a.begin(), a.end());
        int cnt = 0;
        while (!a.empty()) {
            cnt++;
            bool ok = true;
            int val = 0;
            for (int j = a.size() - 1; j >= 0; j--) {
                val = max(val, a[j]);
                int ind = lower_bound(ev.begin(), ev.end(), make_pair(val, -1)) - ev.begin();
                if (pref_max[ind] < a.size() - j) {
                    ok = false;
                    int tt = a.size() - 1 - j;
                    for (int q = 0; q < tt; q++) a.pop_back();
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}