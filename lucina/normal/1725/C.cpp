#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int64_t INF = 1e17;
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

int n, m;
int64_t d[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    prefact();
    cin >> n >> m;

    int64_t peri = 0;
    set <int64_t> s;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> d[i];
        peri += d[i];
        d[i] += d[i - 1];
        s.insert(peri);
    }
    s.insert(0);

    int l = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        bool ok = false;
        if (peri % 2 == 0) {
            if (s.count((peri / 2 + d[i]) % peri)) ok = true;
        }
        if (!ok) l += 1;
    }
    int mat = (n - l) / 2;

    int ans = 0;

    for (int k = 0 ; k <= mat ; ++ k) {
        int res = ncr(mat, k);
        res = mul(res, power(max(0, m - k), l));
        int lft = max(0, m - k);
        int c = mul(lft, sub(lft, 1));
        res = mul(res, power(c, mat - k));
        res = mul(res, ncr(m, k));
        res = mul(res, fac[k]);
        ans = add(ans, res);
    }
    cout << ans << '\n';
}