#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int p[200005], pos[200005];
int a[200005];
int nxt[200005][20];
int last[200005];
int f[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    for (int i = 1; i <= m; ++i) cin >> a[i], a[i] = pos[a[i]];
    for (int i = 1; i <= n; ++i) last[i] = m + 1;
    for (int i = m; i >= 1; --i) {
        nxt[i][0] = last[a[i] % n + 1];
        last[a[i]] = i;
    }
    nxt[m+1][0] = m + 1;
    for (int j = 1; j < 20; ++j) {
        nxt[m+1][j] = m + 1;
        for (int i = 1; i <= m; ++i) {
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        }
    }
    f[m+1] = m + 1;
    for (int i = m; i >= 1; --i) {
        f[i] = i;
        for (int j = 19; j >= 0; --j) if ((n - 1) >> j & 1) f[i] = nxt[f[i]][j];
        f[i] = min(f[i], f[i+1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << int(r >= f[l]);
    }
    cout << endl;
    return 0;
}