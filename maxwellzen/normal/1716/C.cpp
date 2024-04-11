#include <bits/stdc++.h>
using namespace std;

int m;
vector<vector<int>> a;
vector<int> mx;

void solve() {
    cin >> m;
    a.assign(2, vector<int>(m));
    for (int i = 0; i < 2; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    a[0][0] = -1;
    mx.assign(m, 0);

    int snake = 0; // running total
    for (int i = 0; i < m; i++) {
        mx[i] = snake;
        if (i%2==0) {
            snake = max(snake, a[0][i]-2*i+1);
            snake = max(snake, a[1][i]-2*i);
        } else {
            snake = max(snake, a[0][i]-2*i);
            snake = max(snake, a[1][i]-2*i+1);
        }
    }

    int cw = 0, ccw = 0;
    for (int i = m-1; i >= 0; i--) {
        cw = max(cw, a[0][i]-i+1);
        cw = max(cw, a[1][i]-(2*m-1-i)+1);
        ccw = max(ccw, a[0][i]-(2*m-1-i)+1);
        ccw = max(ccw, a[1][i]-i+1);
        if (i%2==0) {
            mx[i] = max(mx[i], cw-i);
        } else {
            mx[i] = max(mx[i], ccw-i);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) ans = min(ans, mx[i] + 2*m-1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}