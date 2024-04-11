#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> type(n), dmg(n);
        for (int i = 0; i < n; ++i) cin >> type[i];
        for (int i = 0; i < n; ++i) cin >> dmg[i];
        vector<int> a, b;
        for (int i = 0; i < n; ++i) if (type[i]) a.push_back(dmg[i]); else b.push_back(dmg[i]);
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        long long ans = 0, ok = 0;
        while (a.size() > b.size()) ok = 1, ans += a.back(), a.pop_back();
        while (b.size() > a.size()) ok = 1, ans += b.back(), b.pop_back();
        if (!ok) ans -= min(a.back(), b.back());
        for (auto x: a) ans += 2 * x;
        for (auto x: b) ans += 2 * x;

        cout << ans << '\n';
    }
    return 0;
}