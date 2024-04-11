#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
void solve() {
    cin >> n;
    vector < int > all;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 2048) continue;
        int y = 0;
        while ((1 << y) < x) y++;
        all.push_back(y);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < 11; i++) {
        vector < int > nall;
        int cnt = 0;
        for (int j = 0; j < all.size(); j++) {
            if (all[j] == i) cnt++;
            else nall.push_back(all[j]);
        }
        for (int p = 0; p < cnt / 2; p++) nall.push_back(i + 1);
        all = nall;
    }
    if (!all.empty()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}