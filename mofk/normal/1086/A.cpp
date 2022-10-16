#include <bits/stdc++.h>

using namespace std;

pair <int, int> x[3];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; ++i) cin >> x[i].first >> x[i].second;
    int ans = 1e7, idx = -1;
    for (int i = 0; i <= 1000; ++i) {
        int mn = min(min(x[0].second, x[1].second), x[2].second);
        int mx = max(max(x[0].second, x[1].second), x[2].second);
        int op = mx - mn + 1;
        for (int j = 0; j < 3; ++j) op += abs(x[j].first - i);
        if (ans > op) {
            ans = op;
            idx = i;
        }
    }
    for (int i = 0; i <= 1000; ++i) {
        int mn = min(min(x[0].first, x[1].first), x[2].first);
        int mx = max(max(x[0].first, x[1].first), x[2].first);
        int op = mx - mn + 1;
        for (int j = 0; j < 3; ++j) op += abs(x[j].second - i);
        if (ans > op) {
            ans = op;
            idx = 1001 + i;
        }
    }
    cout << ans << endl;
    set <pair <int, int> > s;
    if (idx <= 1000) {
        int mn = min(min(x[0].second, x[1].second), x[2].second);
        int mx = max(max(x[0].second, x[1].second), x[2].second);
        for (int i = mn; i <= mx; ++i) s.insert(make_pair(idx, i));
        for (int i = 0; i < 3; ++i) for (int j = min(x[i].first, idx); j <= max(x[i].first, idx); ++j)
            s.insert(make_pair(j, x[i].second));
    }
    else {
        idx -= 1001;
        int mn = min(min(x[0].first, x[1].first), x[2].first);
        int mx = max(max(x[0].first, x[1].first), x[2].first);
        for (int i = mn; i <= mx; ++i) s.insert(make_pair(i, idx));
        for (int i = 0; i < 3; ++i) for (int j = min(x[i].second, idx); j <= max(x[i].second, idx); ++j)
            s.insert(make_pair(x[i].first, j));
    }
    assert(ans == s.size());
    for (auto p: s) cout << p.first << ' ' << p.second << endl;
    return 0;
}