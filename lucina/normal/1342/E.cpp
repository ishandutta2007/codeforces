#include<bits/stdc++.h>
using namespace std;
int const mod = 998244353 ;
int const nax = 2e5 + 10;


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

int main () {

    prefact();

    int n; long long k;
    scanf("%d %lld", &n, &k);

    if (k >= n) return !printf("0");

    int par = n - k;

    int x = 0;

    for (int i = 1 ; i <= par ; ++ i) {
        int q = mul(ncr(par, i), power(par - i, n));

        if (i % 2)
            plusle(x, q);
        else
            minun(x, q);
    }

    int res = power(par, n);
    minun(res, x);

    printf("%d\n", mul(k == 0 ? 1 : 2, mul(ncr(n, par), res)));

}