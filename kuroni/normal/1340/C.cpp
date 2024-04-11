#include <bits/stdc++.h>
using namespace std;

const int N = 10000, G = 1000;

int n, g, r, a[N], dst[N][G];
long long ans = -1;
deque<pair<int, int>> de;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fill(dst[i], dst[i] + G, -1);
    }
    cin >> g >> r;
    sort(a, a + n);
    for (de.push_back({0, 0}), dst[0][0] = 0; !de.empty();) {
        auto [u, t] = de.front(); de.pop_front();
        if (u < n - 1) {
            int nt = t + a[u + 1] - a[u];
            if (nt <= g && dst[u + 1][nt % g] == -1) {
                dst[u + 1][nt % g] = dst[u][t] + (nt == g);
                if (nt < g) {
                    de.push_front({u + 1, nt});
                } else {
                    de.push_back({u + 1, 0});
                }
            }
        }
        if (u > 0) {
            int nt = t + a[u] - a[u - 1];
            if (nt <= g && dst[u - 1][nt % g] == -1) {
                dst[u - 1][nt % g] = dst[u][t] + (nt == g);
                if (nt < g) {
                    de.push_front({u - 1, nt});
                } else {
                    de.push_back({u - 1, 0});
                }
            }
        }
    }
    if (dst[n - 1][0] != -1) {
        ans = 1LL * (dst[n - 1][0] - 1) * (g + r) + g;
    }
    for (int i = 1; i < g; i++) {
        if (dst[n - 1][i] != -1 && (ans == -1 || ans > 1LL * dst[n - 1][i] * (g + r) + i)) {
            ans = 1LL * dst[n - 1][i] * (g + r) + i;
        }
    }
    cout << ans;
}