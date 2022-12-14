#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
using ll = int64_t;
int n;
/**
    regular expression
    S = (BW)*BB(WB)*WW
    S* is accepted by dfa.
    If the string is not generated by this rule
    BWBWBWBWBWBW
    or WBWBWBWB
    The number of BB = WW
    Let's calculate with simple GF
    BB - WW
    ?? = (BB + BW + WW + WB) = (X+1+1/x+1)
        = (x+1)^2/(x)
    ?B = (WB + BB) = (x+1)
    B? = (BB + BW) = (x+1)
    ?W = (WW + BW) = (1/x + 1)
    W? = (WW + WB) = (1 / x + 1)

    (x+1)^2a / x^a (x + 1)^(b) (x+1)^C / X^C

*/
const int MOD = 998244353;
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
int power(int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int C(int n, int r) {
    if (r < 0 || r > n) return 0;
    int u = 1, d = 1;
    for (int i = 0 ; i < r ; ++ i) {
        u = mul(u, n - i);
        d = mul(d, i + 1);
    }
    return mul(u, power(d, MOD - 2));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int a = 0, b = 0, c = 0;
    int n;
    cin >> n;
    int bal = 0;
    int not_same = 1;
    int BW = 1;
    int WB = 1;
    bool exist = false;
    for (int i = 1 ; i <= n ; ++ i) {
        static string s;
        cin >> s;
        if (s[0] == 'W') BW = 0;
        if (s[1] == 'B') BW = 0;
        if (s[0] == 'B') WB = 0;
        if (s[1] == 'W') WB = 0;
        if (s == "??") {
            a += 1;
            not_same = mul(not_same, 2);
        } else if (s == "?B" || s == "B?") {
            b += 1;
        } else if (s == "?W" || s == "W?") {
            c += 1;
        } else {
            if (s == "BB") {
                bal += 1;
                exist = true;
            } else if (s == "WW") {
                bal -= 1;
                exist = true;
            }
        }
    }
    /***
    (x+1)^2a / x^a (x + 1)^(b) (x+1)^C / X^C
    (x+1)^(2a + b + c) / (x^(a + c)
    */
    int M = 2 * a + b + c;
    int shift = a + c;
    /**
        bal - shift - c = 0
        c = bal - shift
    */
    int where = bal - shift;
    /**
        This count the case where, there is no BB, WW
    */

    //cout << "M WHERE " << M << ' ' << where << '\n';
    int ans = C(M, -where);
    if (!exist) {
        ans -= not_same;
        if (ans < 0) ans += MOD;
        //cout << BW << ' ' << WB << '\n';
        ans += BW + WB;
        ans = (ans + MOD) % MOD;
    }
    cout << ans << '\n';
}