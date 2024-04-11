#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    int ret = 1;
    while (n) {
        int t = n % 10;
        if (t) ret *= t;
        n /= 10;
    }
    return ret;
}
int g[1000006];
int cnt[1000006][10];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i < 10; ++i) g[i] = i;
    for (int i = 10; i <= 1000000; ++i) g[i] = g[f(i)];
    for (int i = 1; i <= 1000000; ++i) {
        for (int j = 1; j <= 9; ++j) cnt[i][j] = cnt[i-1][j];
        ++cnt[i][g[i]];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << cnt[r][k] - cnt[l-1][k] << '\n';
    }
    return 0;
}