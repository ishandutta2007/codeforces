#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define int int64_t
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int nax = 3e5 + 10;
bool is_prime[nax];

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; int64_t m;
    cin >> n >> m;

    int64_t mul_prime = 1;

    fill(is_prime, is_prime + nax, true);

    int ans = 0;
    int res = m % MOD;
    int foo = m % MOD;

    for (int i = 2 ; i <= n ; ++ i) {
        if (is_prime[i]) {
            if (mul_prime <= m) {
                mul_prime *= i;
            }
            for (int j = i + i ; j <= n ; j += i) is_prime[j] = false;
        }
        int64_t amb = m / mul_prime;
        res = mul(res, amb % MOD);
        foo = mul(foo, m % MOD);
        plusle(ans, sub(foo, res));
    }
    cout << ans << '\n';


}