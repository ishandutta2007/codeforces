#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 5 * (int)1e5 + 100;
int l[maxN], r[maxN];
int mx[maxN];
const int LOG = 20;
int nxt[LOG][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        l[i]++;
        r[i]++;
        mx[l[i]] = max(mx[l[i]], r[i]);
    }
    for (int i = 1; i < maxN; i++) {
        mx[i] = max(mx[i], mx[i - 1]);
    }
    for (int i = 0; i < maxN; i++) {
        nxt[0][i] = max(mx[i], i);
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 0; i < maxN; i++) {
            nxt[k + 1][i] = nxt[k][nxt[k][i]];
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
        int ans = 0;
        if (nxt[LOG - 1][x] < y) {
            cout << -1 << '\n';
            continue;
        }
        for (int k = LOG - 1; k >= 0; k--) {
            if (nxt[k][x] < y) {
                ans += (1 << k);
                x = nxt[k][x];
            }
        }
        cout << ans + 1     << '\n';
    }
    return 0;
}