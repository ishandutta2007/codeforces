#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, md = 998244353;
using ll = long long ;
ll d;

int mul (int a, int b) {
    return 1LL * a * b % md;
}

int power (int a, int b) {
    int res = 1;
    for ( ; b > 0 ; b >>= 1, a = mul(a, a)) {
        if (b & 1) res = mul(res, a);
    }

    return res;
}


vector<ll> prime;


int main () {

    ll d;
    scanf("%lld", &d);

    int fac[500], inv[500];
    fac[0] = 1;

    for (int i = 1 ; i < 500 ; ++ i) {
        fac[i] = mul(fac[i - 1], i);
        inv[i] = power(fac[i], md - 2);
    }

    for (ll i = 2 ; i * i <= d ; ++ i) {
        if (d % i == 0) {
            prime.push_back(i);
            do {
                d /= i;
            } while (d % i == 0);
        }
    }

    if (d > 1) prime.push_back(d);

    int q;
    scanf("%d", &q);



    int n = prime.size();

    int x[20], y[20];

    for (; q -- ; ) {
        ll a, b;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));

        scanf("%lld %lld", &a, &b);

        int stp = 0;

        for (int i = 0 ; i < n ; ++ i) {
            if (a % prime[i] == 0) {
                ll ca = a;
                while (ca % prime[i] == 0) {
                    ++ x[i];
                 ca /= prime[i];
                }
            }

            if (b % prime[i] == 0) {
                ll cb = b;
                while (cb % prime[i] == 0) {
                    ++ y[i];
                 cb /= prime[i];
                }
            }
        }

        /// x -> y
        for (int i = 0 ;  i < n ; ++ i) {
            if (x[i] < y[i])
            stp += abs(x[i] - y[i]);
        }
        int res = fac[stp];

        for (int i = 0 ; i < n ; ++ i) {
            if (x[i] < y[i]) {
            int q = abs(x[i] - y[i]);
            res = mul(res, inv[q]);
            }
        }

        stp = 0;
        for (int i = 0 ; i < n ; ++ i) {
            if (x[i] > y[i]) {
            stp += x[i] - y[i];
            int q = abs(x[i] - y[i]);
            res = mul(res, inv[q]);
            }
        }

        res = mul(res, fac[stp]);

        printf("%d\n", res);


    }
}
/*
    Good Luck
        -Lucina
*/