#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
using ll = long long;
const int mod = 1e9 + 7;

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

int const Mx = nax;

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

int n;
ll lim;


int main () {
    prefact();

    scanf("%d %lld", &n, &lim);

    ll sum = 0;

    int keep = 1, ans = 0;

    int in2 = (mod + 1) / 2;
    int keep_in2 = 1;


    int from = 1;

    bool first_time = true;

    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d", &x);

        sum += x;

        if (sum > lim) continue;


        keep_in2 = mul(keep_in2, in2);

        keep = add(keep, keep);

        if (sum + i <= lim) {
            plusle(ans, mul(keep, keep_in2));
            from = i;
            continue;
        }

        plusle(keep, ncr(i - 1, from + 1));

        int to = min (i, (int)(lim - sum));

        for (int j = from + 1 ; j > to ; -- j) {
            minun(keep, ncr(i, j));
        }

        //   fprintf(stderr, "i from to %d %d %d\n", i , from, to);
        //   fprintf(stderr, "keep = %d\n", keep);

        from = to;

        plusle(ans, mul(keep, keep_in2));

    }


    printf("%d\n", ans);


}