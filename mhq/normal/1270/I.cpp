#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int k;
const int maxN = (1 << 9) + 2;
ll a[maxN][maxN];
ll b[maxN][maxN];
int t;
int x[maxN], y[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> k;
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            cin >> a[i][j];
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    int addx = (1 << k) - x[0];
    int addy = (1 << k) - y[0];
    for (int i = 0; i < t; i++) {
        x[i] += addx;
        x[i] %= (1 << k);
        y[i] += addy;
        y[i] %= (1 << k);
    }
    int cnt = 0;
    for (int i = k; i >= 0; i--) {
        for (int u = 0; u < (1 << (k - i)); u++) {
            for (int v = 0; v < (1 << (k - i)); v++) {
                if (i == 0) {
                    if (a[u][v] != 0) {
                        cnt++;
                    }
                }
                else {
                    for (int j = 0; j < (1 << i); j++) {
                        for (int l = 0; l < (1 << i); l++) {
                            int nu = u * (1 << i) + j;
                            int nv = v * (1 << i) + l;
                            for (int p = 0; p < t; p++) {
                                int will_u = (nu - x[p] + (1 << k)) % (1 << k);
                                int will_v = (nv - y[p] + (1 << k)) % (1 << k);
                                b[nu][nv] ^= a[will_u][will_v];
                            }
                        }
                    }
                }
            }
        }
        for (int u = 0; u < (1 << k); u++) {
            for (int v = 0; v < (1 << k); v++) {
                a[u][v] = b[u][v];
                b[u][v] = 0;
            }
        }
        if (i == 0) {
            cout << cnt;
            return 0;
        }
        for (int p = 0; p < t; p++) {
            x[p] *= 2;
            x[p] %= (1 << k);
            y[p] *= 2;
            y[p] %= (1 << k);
        }
    }
    return 0;
}