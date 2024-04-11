#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
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


int n;
int a[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    prefact();

    cin >> n;
    int ans = 0;
    a[n + 1] = 0;
    n ++;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        ans = add(ans, ncr(a[i] + i - 1, i));
    }
    cout << ans << '\n';

}
/**
    ....Global round....
*/