#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
int g[maxN];
int cnt[maxN][10];
int f[maxN];
int go(int i) {
    int cur = 1;
    while (i > 0) {
        if (i % 10 == 0) {
            i /= 10;
            continue;
        }
        else (cur = cur * (i % 10));
        i /= 10;
    }
    return cur;
}
void calc() {
    for (int i = 1; i < maxN; i++) {
        f[i] = go(i);
        if (i < 10) g[i] = i;
        else g[i] = g[f[i]];
        for (int j = 1; j <= 9; j++) {
            cnt[i][j] = cnt[i - 1][j] + (g[i] == j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    calc();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << cnt[r][k] - cnt[l - 1][k] << '\n';
    }
    return 0;
}