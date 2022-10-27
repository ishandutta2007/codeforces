#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;
const int mod = 998244353;

void plusle (int &a, int b) {
    if ((a += b) >= mod) a -= mod;
}


int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int f[nax];
int invf[nax];

int ncr (int n, int r) {
    if (r > n) return 0;
   // printf("huh %d %d huh %d\n", n, r, mul(f[n], mul(invf[n - r], invf[r])));

    return mul(f[n], mul(invf[n - r], invf[r]));
}

int main () {

    int ans = 0;
    int n, k;


    scanf("%d %d", &n, &k);

    f[0] = 1;

    for (int i = 1 ; i <= n ; ++ i) {
        f[i] = mul(f[i - 1], i);
     //   printf("fac[%d] %d\n", i, f[i]);
     // copy paste next time
    }

    invf[n] = power(f[n], mod - 2);

    for (int i = n - 1 ; i >= 0 ; -- i) {
        invf[i] = mul(invf[i + 1], i + 1);
    }

    if (k > n) {
        return !printf("0");
    }

    for (int i = 1 ; i <= n ; ++ i) {
        /// suppose min element = i
        int can_div = n / i - 1;

        if (can_div < k - 1) break;

        plusle(ans, ncr(can_div, k - 1));
    }

    printf("%d\n", ans);
}
/*
    Good Luck
        -Lucina
*/