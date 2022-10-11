#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, k, m, u, pre[N], suf[N];
bool chk[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k >> m;
        fill(suf + 1, suf + n + 2, 0);
        fill(pre, pre + n + 1, 0);
        fill(chk + 1, chk + n + 1, false);
        for (int i = 1; i <= m; i++) {
            cin >> u;
            chk[u] = true;
        }
        if ((n - m) % (k - 1) != 0) {
            cout << "NO\n";
        } else {
            bool val = false;
            for (int i = 1; i <= n; i++) {
                pre[i] = pre[i - 1] + (!chk[i]);
            }
            for (int i = n; i >= 1; i--) {
                suf[i] = suf[i + 1] + (!chk[i]);
            }
            for (int i = 1; i <= n; i++) {
                if (chk[i] && pre[i] >= (k - 1) / 2 && suf[i] >= (k - 1) / 2) {
                    val = true;
                    break;
                }
            }
            cout << (val ? "YES\n" : "NO\n");
        }
    }
}