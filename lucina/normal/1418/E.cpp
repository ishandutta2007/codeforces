#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int MOD = 998244353;
void plusle (int &a, int b) {
    if ((a += b) >= MOD ) a -= MOD;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += MOD;
}
int add (int a, int b) {
    return ((a += b) >= MOD) ? a - MOD : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + MOD : a;
}
int mul (int a, int b) {
    return int64_t(a) * b % MOD;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

int n, m;
int d[nax];
int sum[nax];
int inv[nax];
int fac[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> d[i];

    sort(d + 1, d + 1 + n);

    fac[0] = 1;

    for (int i = 1 ; i <= n + 2 ; ++ i) {
        sum[i] = add(sum[i - 1], d[i] % MOD);
        inv[i] = power(i, MOD - 2);
        fac[i] = mul(fac[i - 1], i);
    }


    const int inv_n = power(fac[n], MOD - 2);

    while (m --) {
        int a, b;
        cin >> a >> b;
        /**
            categorized weapon into two type.
            Strength >= b and strength < b

            There are equal number of permutations
            for each types that it will be damaged


        */

        int where = lower_bound(d + 1, d + 1 + n, b) - d;
        /// be careful if b > d[n] ?
        int gt = n - where + 1;
        int ls = n - gt;
        int sum_ls = sum[where - 1];
        int sum_gt = sub(sum[n], sum[where - 1]);

        /**
            for less type
            considered it taking into
            X X X X X X X [Y] X X X X X
            imagine that you have sequences
            of gt + 1 numbers
            you just want to know how many permutations
            that Y is at position a + 1 and later
            by symmetric reasons
            it's eqaul to n! * (gt - a + 1) / (gt + 1)
        */

        int ans = 0;
        if (gt >= a) {
            int cur = mul(gt - a + 1, inv[gt + 1]);
            ans = add(ans, mul(cur, sum_ls));
        }

        /**
            for greater type
            it's the same
            imagine that gt numbers
            you just want to know how many positions
            that Y is at position a + 1 or later
        */
        if (gt >= a) {
            int cur = mul(gt - a, inv[gt]);
            ans = add(ans, mul(cur, sum_gt));
        }

        cout << ans << '\n';

    }
}
/*
    ZZZZZZZ
*/