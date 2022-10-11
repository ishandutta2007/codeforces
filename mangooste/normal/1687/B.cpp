#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    auto query = [&](const vector<bool> &take) {
        cout << "? ";
        for (auto x : take) cout << x;
        cout << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        vector<bool> take(m);
        take[i] = true;
        w[i] = query(take);
    }

    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](const int i, const int j) {
        return w[i] < w[j];
    });

    vector<bool> take(m);
    take[ord[0]] = true;
    int ans = w[ord[0]];
    for (int i = 1; i < m; i++) {
        take[ord[i]] = true;
        int new_sum = query(take);
        if (new_sum == ans + w[ord[i]]) {
            ans += w[ord[i]];
        } else {
            take[ord[i]] = false;
        }
    }
    cout << "! " << ans << endl;
}