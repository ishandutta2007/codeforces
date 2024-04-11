#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int const nax = 2e5 + 10;
const int inv2 = (mod + 1) / 2;

void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += mod ;
}
int add (int a, int b) {
    return (( a += b ) >= mod ) ? a - mod  : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + mod : a;
}
int mul (int a, int b) {
    return 1LL * a * b % mod;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

namespace fact_table {
    const int Mx = 2e5 + 10;
    int fac[Mx], invf[Mx] ;

    void prefact () {
        fac[0] = 1 ;
        for (int i = 1 ; i < Mx ; i ++) {
            fac[i] = mul(fac[i - 1], i);
        }
        invf[Mx - 1] = power (fac[Mx - 1] ,  mod - 2 );
        for (int i = Mx - 2 ; i >= 0 ; i --) {
            invf[i] = mul(invf[i + 1], i + 1);
        }
    }

    int ncr (int N, int R) {
        if (R > N) return 0;
        if (R == 0 || R == N) return 1;
        return mul (fac[N], mul(invf[N - R], invf[R]));
    }
}
using fact_table::ncr;
using fact_table::prefact;


int a[nax];
int b[nax];
int n, k;
int ans;

int main () {
    prefact();

    scanf("%d %d", &n, &k);

    if (k == 1) {
        puts("0");
        return 0;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        b[i % n + 1] = a[i];
    }

    int same = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        same += (a[i] == b[i]);
    }

    n -= same;

    for (int no_dif = 0 ; no_dif <= n ; ++ no_dif) {
        int res = n - no_dif;
        int tot_way = power(2, res);
        int zero_way = 0;
        if (res % 2 == 0) {
            zero_way = ncr(res, res / 2);
        }
        minun(tot_way, zero_way);
        tot_way = mul(tot_way, inv2);
        tot_way = mul(tot_way, ncr(n, no_dif));
        tot_way = mul(tot_way, power(k - 2, no_dif));

        ans = add(ans, tot_way);
    }

    printf("%d\n", mul(ans, power(k, same)));

}