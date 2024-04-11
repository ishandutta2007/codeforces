#include <bits/stdc++.h>

using namespace std;

long long a[30][30];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
        a[i][j] = ((long long)j << (i + j));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
            if (j < n - 1) cout << ' ';
            else cout << endl;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        long long v;
        cin >> v;
        vector<pair<int, int>> ans;
        int x = 0, y = 0;
        ans.push_back({x, y});
        for (int i = 1; i < n + n - 1; ++i) {
            long long tar = 1ll << (i + 1);
            if (x + 1 < n && (v - a[x+1][y]) % tar == 0) {
                v -= a[x+1][y];
                ++x;
            }
            else {
                v -= a[x][y+1];
                ++y;
            }
            ans.push_back({x, y});
        }
        for (auto z: ans) cout << z.first + 1 << ' ' << z.second + 1 << endl;
    }
    return 0;
}