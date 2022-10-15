//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        int n = s.length();
        vector<pair<int, int>> kek(n + 1);
        kek[0] = { 0, 0 };
        for (int i = 0; i < n; i++){
            char c = s[i];
            if (c == 'W') {
                x++;
            }
            if (c == 'S') {
                x--;
            }
            if (c == 'D') {
                y++;
            }
            if (c == 'A') {
                y--;
            }
            kek[i + 1] = { x, y };
        }
        vector<int> suf_x[2];
        vector<int> suf_y[2];
        suf_x[0].resize(n + 1);
        suf_x[1].resize(n + 1);
        suf_y[0].resize(n + 1);
        suf_y[1].resize(n + 1);
        suf_x[0][n] = suf_x[1][n] = kek[n].first;
        suf_y[0][n] = suf_y[1][n] = kek[n].second;
        for (int i = n - 1; i >= 0; i--) {
            suf_x[0][i] = min(suf_x[0][i + 1], kek[i].first);
            suf_x[1][i] = max(suf_x[1][i + 1], kek[i].first);
            suf_y[0][i] = min(suf_y[0][i + 1], kek[i].second);
            suf_y[1][i] = max(suf_y[1][i + 1], kek[i].second);
        }
        ll ans = ll(suf_x[1][0] - suf_x[0][0] + 1) * (suf_y[1][0] - suf_y[0][0] + 1);
        int lx = 0, rx = 0;
        int ly = 0, ry = 0;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, ll(max(suf_x[1][i] + 1, max(rx, kek[i - 1].first + 1)) - min(lx, suf_x[0][i] + 1) + 1)
                  * (max(suf_y[1][i], ry) - min(ly, suf_y[0][i]) + 1)); // W
            ans = min(ans, ll(max(suf_x[1][i] - 1, rx) - min(min(lx, kek[i - 1].first - 1), suf_x[0][i] - 1) + 1)
                  * (max(suf_y[1][i], ry) - min(ly, suf_y[0][i]) + 1)); // S
            ans = min(ans, ll(max(suf_x[1][i], rx) - min(lx, suf_x[0][i]) + 1)
                  * (max(suf_y[1][i] - 1, ry) - min(min(ly, kek[i - 1].second - 1), suf_y[0][i] - 1) + 1)); // A
            ans = min(ans, ll(max(suf_x[1][i], rx) - min(lx, suf_x[0][i]) + 1)
                  * (max(suf_y[1][i] + 1, max(ry, kek[i - 1].second + 1)) - min(ly, suf_y[0][i] + 1) + 1)); // D
            lx = min(lx, kek[i].first);
            rx = max(rx, kek[i].first);
            ly = min(ly, kek[i].second);
            ry = max(ry, kek[i].second);
        }
        cout << ans << '\n';
    }
    return 0;
}