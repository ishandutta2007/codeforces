#include <bits/stdc++.h>

using namespace std;

int f[20][200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 200000; ++i) for (int j = 0; j < 20; ++j) if (i >> j & 1) f[j][i] = f[j][i-1] + 1; else f[j][i] = f[j][i-1];

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 20; ++i) ans = max(ans, f[i][r] - f[i][l-1]);
        cout << r - l + 1 - ans << '\n';
    }
    return 0;
}