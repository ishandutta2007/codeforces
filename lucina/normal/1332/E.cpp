#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, mod = 998244353 ;

int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 ,  a = mul(a, a))
        if (b & 1 )res = mul(res, a);
    return res;
}

int n, m, l, r;

#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL

const int Mx = 3;
struct matrix{
    int m[Mx][Mx];
    static const long long mod2 = 1LL * mod * mod;
    matrix() {
        memset(m, 0, sizeof(m));
    }
    int * operator [](int r){
        return m[r];
    }
    void print(){
        eprintf("===========\n");
        for(int i = 0 ; i < Mx ;i  ++)
            for(int j = 0 ;j < Mx ;j ++)
                eprintf("%d%c", m[i][j], j == Mx - 1 ? '\n' : ' ');
        eprintf("===========\n");
    }
    friend matrix operator + (matrix & x, matrix & y){
        matrix res;
        for(int i = 0 ; i < Mx ; i ++)
            for(int j = 0 ;j < Mx ;j ++)
                res[i][j] = add(x[i][j], y[i][j]);
        return res;
    }
    friend matrix operator * (matrix & x, matrix & y){
        matrix res;
        for(int i = 0 ; i < Mx ; i ++)
            for(int j =0 ;j < Mx ; j ++){
                long long c = 0;
                for(int r = 0 ; r < Mx ; r ++){
                    c += 1LL * x[i][r] * y[r][j];
                    if(c >= mod2) c -= mod2;
            }
            res[i][j] = c % mod;
        }
        return res;
    }
};
matrix M_power(matrix x, long long y){
    matrix res;
    for(int i = 0  ;i < Mx ;i ++)
        res[i][i] = 1;
    for(; y > 0 ; y >>= 1){
        if(y & 1){
           res = res * x;
        }
        x = x * x;
    }
    return res;
}



int main () {
    scanf("%d %d %d %d", &n, &m, &l, &r);
    int odd = (r - l + 1) / 2;
    int even = odd;
    if (r % 2 == l % 2) {
        if (l % 2) ++ odd;
        else ++ even;
    }



    matrix now;
    now[0][0] = even;
    now[1][0] = odd;

    long long ret = 1LL * n * m - 1;

    matrix t;
    t[0][0] = even;
    t[0][1] = odd;
    t[1][0] = odd;
    t[1][1] = even;

    t = M_power(t, ret);


    matrix res = t * now;

    res.print();

    int parity = (n % 2) * (m % 2);

    int ans = res[0][0];

    if (parity) {
        ans = add(ans, res[1][0]);
    }

    printf("%d\n", ans);

}
/*
    Good Luck
        -Lucina
*/