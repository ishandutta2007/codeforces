#include <bits/stdc++.h>

using namespace std;
//#pragma GCC optimize("O3")

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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int n;
const int maxN = 3e5 + 10;
int a[maxN];
int dp[maxN];
int ex[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    dp[0] = (n - 1);
    int P = mult(n - 2, pw(n - 1, mod - 2));
    int rev_s = pw(S, mod - 2);
    for (int i = 1; i <= S - 1; i++) {
        int coef = sub(1, sum(mult(i, rev_s), mult(S - i, mult(P, rev_s))));
        int val2 = sum(1, mult(dp[i - 1], mult(i, rev_s)));
        dp[i] = mult(val2, pw(coef, mod - 2));
    }
    ex[S] = 0;
    for (int i = S - 1; i >= 0; i--) {
        ex[i] = sum(ex[i + 1], dp[i]);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot = sum(tot, ex[a[i]]);
    }
    tot = sub(tot, mult(ex[0], n - 1));
    tot = mult(tot, pw(n, mod - 2));
    cout << tot;
    return 0;
}