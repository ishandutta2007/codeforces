#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tar; cin >> n >> tar;
    vector a(n, vector<int>(n));
    vector<int> cnt(n * n + 1);
    vector<int> le(n * n + 1, n), ri(n * n + 1, 0),
        up(n * n + 1, n), dn(n * n + 1, 0);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            int v = a[i][j];
            le[v] = min(le[v], i);
            ri[v] = max(ri[v], i);
            up[v] = min(up[v], j);
            dn[v] = max(dn[v], j);
            if (cnt[v]++ == 0) {
                tot++;
            }
        }
    }
    if (tot <= tar) {
        cout << tar - tot << '\n';
    } else {
        vector rem(n, vector(n, vector<int>()));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rem[i][j].resize(min(i, j) + 1);
            }
        }
        for (int v = 1; v <= n * n; v++) {
            if (cnt[v] == 0) {
                continue;
            }
            for (int l = 0; l <= le[v]; l++) {
                int u = up[v];
                int r = ri[v], d = dn[v];
                // l, u to cover r, d
                int dst = max(r - l, d - u);
                r = l + dst, d = u + dst;
                if (r < n && d < n) {
                    rem[r][d][dst]++;
                }
            }
            for (int u = 0; u < up[v]; u++) {
                int l = le[v];
                int r = ri[v], d = dn[v];
                // l, u to cover r, d
                int dst = max(r - l, d - u);
                r = l + dst, d = u + dst;
                if (r < n && d < n) {
                    rem[r][d][dst]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int dst = 0; dst <= i && dst <= j; dst++) {
                    if (dst > 0) {
                        rem[i][j][dst] += rem[i - 1][j - 1][dst - 1];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int dst = 0; dst <= i && dst <= j; dst++) {
                    if (dst > 0) {
                        rem[i][j][dst] += rem[i][j][dst - 1];
                    }
                    if (tot - rem[i][j][dst] == tar || tot - rem[i][j][dst] + 1 == tar) {
                        return cout << 1, 0;
                    }
                }
            }
        }
        cout << 2;
    }
}