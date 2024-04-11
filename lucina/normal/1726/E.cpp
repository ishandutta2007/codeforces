#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int MX = 2e6 + 10;
int fac[MX], inv_fac[MX];
void prefact() {
    fac[0] = 1;
    for (int i = 1 ; i < MX ; ++ i) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv_fac[MX - 1] = power(fac[MX - 1], MOD - 2);
    for (int i = MX - 2 ; i >= 0 ; -- i) {
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);
    }
}

int ncr(int N, int R) {
    if (R > N) return 0;
    return mul(fac[N], mul(inv_fac[N - R], inv_fac[R]));
}
/**

1
2
4
12
32
100
312
1076
3772
14112
54080
217432 -> 217672 (very close, did I overcount something?)
896856 -> 898536
*/

int n;
int f[nax];
int pref_mul[nax];
/**
    two adjacent elements, waiting,
    one elements waiting,
    last element used?

*/
int g[nax];

void solve() {
    cin >> n;
    /**
        it's kinda stupid to write brute force below, waste of time. :P
        So the only valid cycles are

        1) xx   xx
        has two ways
        2) and
        x       x swap directly one way
        3) do nothing

        Let's f(x) be the number of ways to select 2x blocks from n

        [] [] [] [] [] []
        so x + 1 places for insert
        c1 + c2 + ... + c(x + 1) = n - 2x
        C(n - 2x + x, x) = C(n - x, x)

        So, let's fix x
        The answer is just

        for u = 0, 2, ...
        C(n - x, x) * (2^x) * C(n - 2x, u) * f(u)
        f(u) = C(u, 2) * C(u - 2, 2) * .....
        we can get O(1) formulta, but not necessary
    */
    f[0] = 1;
    pref_mul[0] = 1;
    g[0] = g[1] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        if (i > 0) f[i] = f[i - 1], pref_mul[i] = pref_mul[i - 1];
        if (i % 2 == 1) {
            f[i] = mul(f[i], i);
            pref_mul[i] = mul(pref_mul[i], f[i]);
        }
        if (i > 1) g[i] = add(g[i-1], mul(i-1, g[i-2]));
    }


    /**
        1 -> 3 -> 2 -> 4
    */
    int ans = 0;
    for (int x = 0 ; 4 * x <= n ; ++ x) {
            //c1 + c2 + c3 + .... + c(2*x + 1) = n - 4 * x = 5 - 1
            //c1 + c2 +
            /**
                [ ]x[ ]
                [ ][ ]x
                x[][]
            **/
        int res = ncr(n -  2 * x, 2 * x);
        res = mul(res, f[2 * x]);
        res = mul(res, power(2, x)); // of course, it should multiply by 8
        /**
            5 * 3 * 1, hm it should be 15 * 8, isn't it
        */
        //cout << x << ' ' << res << '\n';

        int up = n - 4 * x;
        int to = up % 2 ? up - 1 : up;
        int sum = 0;
        /**
            1 2
            C(4, 2)
            the number of rest members are
        */
/*
        for (int d = 0 ; d * 2 <= up ; ++ d) {
            sum = add(sum, mul(ncr(up, 2 * d), f[2 * d]));
        }*/
        res = mul(res, g[up]);
     //   cout << res << ",";
        ans = add(ans, res);
        /**
            C(up, 0) * c(up, 2) * c(up, 4) * .... * C(up, to)
        */
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    prefact();
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
    //for (int x=0; x <= 10; ++ x) cout << g(x) << " ";
}
/**
';

*/