#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1005;
int n[2];
int x[2][maxN], y[2][maxN], l[2][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n[0] >> n[1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> x[i][j] >> y[i][j] >> l[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n[0]; i++) {
        for (int j = 0; j < n[1]; j++) {
            int x1 = x[0][i];
            int y1 = y[1][j];
            ans = max(ans, min({y1 - y[0][i], y[0][i] + l[0][i] - y1, x1 - x[1][j], x[1][j] + l[1][j] - x1}));
        }
    }
    cout << ans;
    return 0;
}