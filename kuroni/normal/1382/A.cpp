#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int te;
    cin >> te;
    while (te--) {
        int n, m, ans = -1, u;
        cin >> n >> m;
        vector<bool> chk(1005, false);
        for (int i = 1; i <= n; i++) {
            cin >> u;
            chk[u] = true;
        }
        for (int i = 1; i <= m; i++) {
            cin >> u;
            if (chk[u]) {
                ans = u;
            }
        }
        if (ans == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n1 " << ans << '\n';
        }
    }
}