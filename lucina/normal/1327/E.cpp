#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10, mod = 998244353;

void plusle (int &a, int b) {
    if ((a += b) >= mod) a -= mod;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int n, p[nax];



int main () {
    scanf("%d", &n);

    p[0] = 1;

    for (int i = 1 ; i < n ; ++ i) {
        p[i] = mul(p[i - 1], 10);
    }



    for (int i = 1 ; i < n ; ++ i) {

        int res = 0;
        plusle(res, mul(18, p[n - i - 1]));
        plusle(res, mul(n - i - 1, mul(81, n - i - 2 < 0 ? 1 : p[n - i - 2])));

        printf("%d ", mul(res, 10));
    }
    return !printf("10");

}