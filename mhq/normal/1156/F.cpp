#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 5005;
int inv[maxN];
int ank[maxN];
int n;
int cnt[maxN];
int f[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = sum(f[i][j], f[i - 1][j]);
            if (j) {
                f[i][j] = sum(f[i][j], mult(cnt[i], f[i - 1][j - 1]));
            }
        }
    }
    ank[0] = 1;
    int prob = 0;
    for (int i = 1; i <= n; i++) {
        ank[i] = mult(ank[i - 1], inv[n - i + 1]);
    }
    for (int pref = 0; pref <= n - 1; pref++) {
        for (int num = 0; num <= n; num++) {
            if (f[pref][num] == 0) continue;
            if (cnt[pref + 1] <= 1) continue;
            int coef = mult(f[pref][num], ank[num + 2]);
            int c2 = mult(cnt[pref + 1], sub(cnt[pref + 1], 1));
            //cout << c2 << " " << coef << " " << num << " " << mult(ank[2], )
            prob = sum(prob, mult(c2, coef));
        }
    }
    cout << prob;
    return 0;
}