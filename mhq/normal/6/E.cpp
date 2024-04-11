#include <bits/stdc++.h>
using namespace std;
int n, k;
const int maxN = (int)1e5 + 10;
int h[maxN];
int rb[maxN][24];
int rs[maxN][24];
int lb[maxN][24];
int ls[maxN][24];
pair < int, int > ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        rb[i][0] = rs[i][0] = lb[i][0] = ls[i][0] = h[i];
    }
    for (int j = 1; j < 24; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << (j)) <= n + 1) {
                rb[i][j] = max(rb[i][j - 1], rb[i + (1 << (j - 1))][j - 1]);
                rs[i][j] = min(rs[i][j - 1], rs[i + (1 << (j - 1))][j - 1]);
            }
            if (i - (1 << j) >= 0) {
                lb[i][j] = max(lb[i][j - 1], lb[i - (1 << (j - 1))][j - 1]);
                ls[i][j] = min(ls[i][j - 1], ls[i - (1 << (j - 1))][j - 1]);
            }
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        int r = i + 1;
        for (int j = 23; j >= 0; j--) {
            int t = 1 << j;
            if ((r + t) > n + 1) continue;
            if (rb[r][j] > h[i] + k || rs[r][j] < h[i]) continue;
            r = r + t;
        }
        r = r - 1;
        int l = i - 1;
        for (int j = 23; j >= 0; j--) {
            int t = 1 << j;
            if (l - t < 0) continue;
            if (lb[l][j] > h[i] + k || ls[l][j] < h[i]) continue;
            l = l - t;
        }
        l = l + 1;
        ans[i] = make_pair(l, r);
        mx = max(mx, r - l  + 1);
        //cout << l << " " << r << '\n';
    }
    int prvl = -1;
    vector < pair < int, int > > an;
    for (int i = 1; i <= n; i++) {
        if (ans[i].first != prvl && ans[i].second - ans[i].first + 1 == mx) {
            prvl = ans[i].first;
            an.push_back(ans[i]);
        }
    }
    cout << mx << " " << an.size() << '\n';
    for (int i = 0; i < an.size(); i++) {
        cout << an[i].first << " " << an[i].second << '\n';
    }
    return 0;
}