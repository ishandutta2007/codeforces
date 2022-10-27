#include<bits/stdc++.h>
using namespace std;
int const nax = 2e6 + 10;
const int mod = 1000000007;//
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

int f[nax][2];


int main () {
    f[3][1] = 4;
    f[4][0] = 4;
    f[4][1] = 4;


    int T;

    /**
        if (i % 3) == 1
        f[i][0] = f[i][1]
        if (i % 3) == 2
        f[i][0] > f[i][1]
        if (i % 3) == 0
        f[i][0] < f[i][1]
    */

    auto get_max_val = [&] (int x) -> int{
        if (x % 3 == 1) return f[x][0];
        if (x % 3 == 2) return f[x][0];
        return f[x][1];
    };

    for (int i = 5 ; i < nax ; ++ i) {
        f[i][1] = add(add(4, mul(f[i - 2][0], 2)), f[i - 1][0]);;
        f[i][0] = add(mul(2, get_max_val(i - 2)), get_max_val(i - 1));
    }

    for (scanf("%d", &T) ; T -- ;) {
        int x;
        scanf("%d", &x);
        printf("%d\n", get_max_val(x));
    }
}
/*
    Leon is the best girl in A17.
*/