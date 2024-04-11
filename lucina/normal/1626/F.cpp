#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int L = 720720*17;
int n;
int M, x, y, k;
int a;
int dp[L];
int ndp[L];

int main() {
    cin >> n >> a >> x >> y >> k >> M;
    /**
        LCM of first 16 integers is 720720 = L.
        The contribution of each position is basically.
        A % lcm(x1, x2, .., xc) where x_i is selected position

        for each value A, everything is symmetric. We need to find a way
        to precompute and answer for each A in O(1).

        Look at the expected value, each position the probability of being chosen is
        (1 / n) and there are k positions, we can just multiply by
        k * (n ^ (k - 1)) for based value and consider subtraction seperately,

        for value A, split it into [A - (A % L)] + (A % L),
        the first part is static, we can compute it in O(1),
        for the second part, we need to do dp to precompute it O(L * K)
    */
    const int inv_n = power(n, MOD - 2);
    for (int i = k, c = 1 ; i >= 1 ; -- i) {
        for (int j = L - 1 ; j >= 0 ; -- j) {
            dp[j] = add(mul(dp[j], n - 1), add(dp[j - j % i], mul(j, c)));
        }
        c = mul(c, n);
    }
    int ans = 0;
    int A = mul(k, power(n, k - 1));
    for (int i = 0 ; i < n ; ++ i) {
        int q = a - a % L, r = a % L;
        ans = add(ans, mul(A, q));
        ans = add(ans, dp[r]);
        a = (1LL * a * x + y) % M;
    }
    cout << ans << '\n';
}