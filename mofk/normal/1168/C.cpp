#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[300005];
int last[20];
int nxt[300005][20];
int f[300005][20];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < 20; ++j) last[j] = n + 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 20; ++j) if (a[i] >> j & 1) {
            nxt[i][j] = last[j];
            last[j] = i;
            f[i][j] = i;
        } else nxt[i][j] = f[i][j] = n + 1;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 20; ++j) {
            int k = nxt[i][j];
            if (k > n) continue;
            for (int t = 0; t < 20; ++t)
                f[i][t] = min(f[i][t], f[k][t]);
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        int ok = 0;
        for (int j = 0; j < 20; ++j) if (a[y] >> j & 1) {
            if (f[x][j] <= y) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "Shi" : "Fou") << '\n';
    }
    return 0;
}