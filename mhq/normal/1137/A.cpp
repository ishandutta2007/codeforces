#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1005;
int a[maxN][maxN];
int n, m;
int gre[2][maxN][maxN], smale[2][maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int row = 1; row <= n; row++) {
        vector < pair < int, int > > all;
        for (int col = 1; col <= m; col++) {
            all.emplace_back(a[row][col], col);
        }
        sort(all.begin(), all.end());
        int cur = 0;
        for (int i = 0; i < all.size(); i++) {
            if (i > 0 && all[i].first != all[i - 1].first) cur++;
            smale[0][row][all[i].second] = cur;
        }
        cur = 0;
        for (int i = all.size() - 1; i >= 0; i--) {
            if (i + 1 < all.size() && all[i].first != all[i + 1].first) cur++;
            gre[0][row][all[i].second] = cur;
        }
    }
    for (int col = 1; col <= m; col++) {
        vector < pair < int, int > > all;
        for (int row = 1; row <= n; row++) {
            all.emplace_back(a[row][col], row);
        }
        sort(all.begin(), all.end());
        int cur = 0;
        for (int i = 0; i < all.size(); i++) {
            if (i > 0 && all[i].first != all[i - 1].first) cur++;
            smale[1][all[i].second][col] = cur;
        }
        cur = 0;
        for (int i = all.size() - 1; i >= 0; i--) {
            if (i + 1 < all.size() && all[i].first != all[i + 1].first) cur++;
            gre[1][all[i].second][col] = cur;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << 1 + max(smale[0][i][j], smale[1][i][j]) + max(gre[0][i][j], gre[1][i][j]) << " ";
        }
        cout << '\n';
    }
}