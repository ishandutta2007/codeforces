#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int inv(int a) {
    return pw(a, mod - 2);
}

int n;
const int maxN = 2 * (int)1e5 + 100;
int l[maxN], r[maxN];
int val[maxN];
int len[maxN];
int prob[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        len[i] = r[i] - l[i] + 1;
        prob[i] = inv(len[i]);
    }
    int total = 0;
    for (int i = 1; i + 1 <= n; i++) {
        int len_int = min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1;
        if (len_int < 0) len_int = 0;
        val[i] = sub(1, mult(len_int, mult(prob[i], prob[i + 1])));
        total = sum(total, val[i]);
    }
    int ans = 0;
    for (int i = 1; i + 1 <= n; i++) {
        ans = sum(ans, val[i]);
        int res = sub(total, val[i]);
        if (i > 1) res = sub(res, val[i - 1]);
        if (i + 1 < n) res = sub(res, val[i + 1]);
        // indep
        ans = sum(ans, mult(res, val[i]));

        // val[i - 1], val[i + 1]
        if (i > 1) {
            int f = sum(val[i - 1], val[i]);
            //cout << val[i - 1] << " " << val[i] << " ggg" << endl;
            f = sub(f, 1);
            int total_int = min({r[i - 1], r[i], r[i + 1]}) - max({l[i - 1], l[i], l[i + 1]}) + 1;
            if (total_int < 0) total_int = 0;
            f = sum(f, mult(total_int, mult(prob[i], mult(prob[i - 1], prob[i + 1]))));
            //cout << i << " " << f << " ggg" << endl;
            ans = sum(ans, mult(2, f));
        }
    }
    cout << sum(mult(2, total), sum(ans, 1));
    return 0;
}