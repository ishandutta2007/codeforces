#include <bits/stdc++.h>

using namespace std;

const int inf = 1e6;
int n;
int x[1005], y[1005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i], x[i] += inf, y[i] += inf;
    while (true) {
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; ++i) {
            if ((x[i] + y[i]) % 2 == 0) ++c1; else ++c2;
        }
        if (c1 && c2) {
            vector <int> ans;
            for (int i = 1; i <= n; ++i) if ((x[i] + y[i]) % 2 == 0) ans.push_back(i);
            cout << ans.size() << endl;
            for (auto f: ans) cout << f << ' '; cout << endl;
            return 0;
        }
        int mn = 0;
        for (int i = 1; i <= n; ++i) {
            int f = x[i] + y[i], g = x[i] - y[i];
            if (f & 1) ++f, ++g;
            x[i] = f / 2, y[i] = g / 2;
            mn = min(mn, y[i]);
        }
        for (int i = 1; i <= n; ++i) y[i] -= mn;
    }
    return 0;
}