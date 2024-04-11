#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 65536;
int add(int a, int b) {
    return (a += b) >= MOD ? a - MOD : a;
}

int sub(int a, int b) {
    return ((a -= b) < 0) ? a + MOD : a;
}

int mul(int64_t a, int b) {
    return a * b % MOD;
}

int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int p[25][N];
int n, m;



int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;

    int fac = 1;

    for (int i = 1 ; i <= n ; ++ i) {
        fac = mul(fac, i);
        for (int j = 1 ; j <= m ; ++ j) {
            cin >> p[i][j];
        }
    }

    int ans = 0;

    for (int i = 1 ; i <= m ; ++ i) {
        static int b[21];
        memset(b, 0, sizeof(b));
        for (int j = 1 ; j <= n ; ++ j) {
            b[p[j][i] - 1] += 1;
        }

        int res = 1;
        int foo = 0;
        for (int j = n ; j >= 1 ; -- j) {
            foo += b[j];
            res = mul(res, foo);
            foo -= 1;
        }

        ans = add(ans, sub(fac, res));
    }

    cout << 1LL * ans * power(fac, MOD - 2) % MOD << '\n';

}