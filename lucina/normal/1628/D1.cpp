#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
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
const int INV2 = (MOD + 1) >> 1;
int n, m, k;

void solve() {
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; ++ i) {
        int x = 2 * i - 1;
        int path = ncr(n - 1, m - i);
        plusle(ans, mul(x, path));
    }
    ans = mul(ans, power(INV2, n - 1));
    cout << mul(ans, k) << '\n';
}

int main() {
    prefact();
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}