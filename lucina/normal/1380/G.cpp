#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int mod = 998244353;
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

int a[nax];
int n;



int main () {
    scanf("%d", &n);

    for (int i = 0 ; i < n; ++ i)
        scanf("%d", a + i);
    sort(a, a + n, greater<int>());

    for (int i = 1 ; i < n ; ++ i) {
        a[i] = add(a[i], a[i - 1]);
    }

    /**
        try brute force
    */

    int inv_n = power(n, mod - 2);

    for (int k = 1 ; k <= n ; ++ k) {
        int ans = 0, from = a[k - 1];
        for (int i = k, j = 1 ; i < n ; i += k, ++ j) {
            int to = min(n - 1, i + k - 1);

            int cur = sub(a[to], from);
            from = a[to];
            ans = add(ans, mul(j, cur));
        }
        printf("%d ", mul(ans, inv_n));
        //printf("%d ", mul(ans, inv_n));
    }
}
/*
    Rorona is not childish.
*/