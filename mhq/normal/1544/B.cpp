#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int h, w;
        cin >> h >> w;
        vector<pair<int,int>> ord;
        vector<vector<int>> a(h, vector<int>(w, 0));
        for (int i = 0; i < w; i++) ord.emplace_back(0, i);
        for (int i = 0; i < h; i++) ord.emplace_back(i, w - 1);
        for (int i = w - 1; i >= 0; i--) ord.emplace_back(h - 1, i);
        for (int i = h - 1; i >= 0; i--) ord.emplace_back(i, 0);
        for (auto& it : ord) {
            bool can = true;
            if (a[it.first][it.second] == 1) continue;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int nx = it.first + x;
                    int ny = it.second + y;
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (a[nx][ny] == 1) {
                        can = false;
                        break;
                    }
                }
            }
            if (can) a[it.first][it.second] = 1;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) cout << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}