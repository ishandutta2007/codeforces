#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, h;
int ans[105][105], g[105], f[105];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tp;
            cin >> tp;
            if (tp == 0) cout << 0 << " ";
            else {
                cout << min(g[i], f[j]) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}