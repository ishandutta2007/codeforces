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



int n;
int64_t a[nax];


void solve() {
    cin >> n;
    int64_t sum = 0;
    map <int64_t, int> f;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        sum += a[i];
        if (i < n) f[sum] += 1;
    }

    int res = 1;
    /**
        just a side note: 
        to prove that sum (ncr(a, i) * ncr(b, i)) i = 0...min(a, b)
        = ncr(a + b, a)
        We can imagine it this way, 
        ncr(a + b, a) is just a way to split to two set of size a and b
        [1, ......a] [a + 1 ..... b]
        Let the two set be like this from the start, then
        we can swap exactly, i members of first set and second set
        ncr(a, i) * ncr(b, i) and iterate over i, this prove the identity
    */

    for (auto [x, c] : f) {
        if (x * 2 == sum) {
            res = mul(res, power(2, c));
        } else if (x * 2 < sum) {
            if (f.count(sum - x)) {
                int d = f[sum - x];
                res = mul(res, ncr(c + d, d));
            }
        }
    }
    cout << res << '\n';

}

int main() {
    prefact();
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}