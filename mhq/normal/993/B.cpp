#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[15][2];
int y[15][2];
vector < int > ans;
pair < int, int > intersect(int i, int j) {
    pair < int, int > t;
    t.first = -1;
    t.second = -1;
    for (int k = 0; k < 2; k++) {
        if (x[i][0] == y[j][k]) t.first = x[i][0];
        if (x[i][1] == y[j][k]) t.second = x[i][1];
    }
    return t;
}
set < int > xx[15];
set < int > yy[15];
bool can[15];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) cin >> x[i][j];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> y[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pair < int, int > k = intersect(i, j);
            if (k.first != -1 && k.second != -1) continue;
            if (k.first != -1) {
                can[k.first] = true;
                xx[i].insert(k.first);
                yy[j].insert(k.first);
            }
            if (k.second != -1) {
                xx[i].insert(k.second);
                yy[j].insert(k.second);
                can[k.second] = true;
            }
        }
    }
    int cnt = 0;
    int ans = -1;
    for (int i = 1; i <= 9; i++) {
        if (can[i]) {
            cnt++;
            ans = i;
        }
    }
    if (cnt == 1) {
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (xx[i].size() == 2) {
            cout << -1;
            return 0;
        }
    }
    for (int j = 1; j <= m; j++) {
        if (yy[j].size() == 2) {
            cout << -1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}