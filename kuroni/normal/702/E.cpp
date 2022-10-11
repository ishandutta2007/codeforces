#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LG = 40;

int n, f[N][LG], w[N], m[N][LG];
long long k, s[N][LG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> f[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        s[i][0] = m[i][0] = w[i];
    }
    for (int j = 1; j < LG; j++) {
        for (int i = 0; i < n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            s[i][j] = s[i][j - 1] + s[f[i][j - 1]][j - 1];
            m[i][j] = min(m[i][j - 1], m[f[i][j - 1]][j - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        long long su = 0;
        int mi = INT_MAX;
        int u = i;
        for (int j = 0; j < LG; j++) {
            if (k >> j & 1) {
                su += s[u][j];
                mi = min(mi, m[u][j]);
                u = f[u][j];
            }
        }
        cout << su << " " << mi << '\n';
    }
}