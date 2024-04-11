#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxK = 5105;
int c[maxK][maxK];
int inv[maxK];
int p, s, r;
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    else {
        int res = pw(a, b / 2);
        return mult(res, res);
    }
}
int get_inv(int a) {
    return pw(a, mod - 2);
}
int get_num(int s, int lim, int cnt) {
    // s_1 + .. + s_a = b -> c[b + a - 1][a - 1]
    if (cnt == 0) {
        return (s == 0);
    }
    if (lim == 0) {
        return 0;
    }
    else {
        // s
        int cur = 0;
        for (int bigger = 0; bigger <= cnt; bigger++) {
            if (bigger * lim > s) break;
            int coef = mult(c[cnt][bigger], c[s - bigger * lim + cnt - 1][cnt - 1]);
            if (bigger & 1) cur = sub(cur, coef);
            else cur = sum(cur, coef);
        }
        //cout << cur << " " << s << " " << lim << " " << cnt << endl;
        return cur;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[1] = 1;
    for (int i = 2; i < maxK; i++) {
        inv[i] = mult(mod - (mod / i), inv[mod % i]);
    }
    c[0][0] = 1;
    for (int i = 1; i < maxK; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    cin >> p >> s >> r;
    // s - r + p - 1
    // (1 / cnt)
    int all = c[s - r + p - 1][p - 1];
    int ans = 0;
    for (int i = r; i <= s; i++) {
        int left = s - i;
        for (int cnt = 0; cnt <= p - 1; cnt++) {
            if (cnt * i > left) break;
            ans = sum(ans, mult(inv[cnt + 1], mult(c[p - 1][cnt], get_num(left - cnt * i, i, p - 1 - cnt))));
            // (1 / (cnt + 1)) * coef / all;
        }
    }
    cout << mult(ans, get_inv(all));
    return 0;
}