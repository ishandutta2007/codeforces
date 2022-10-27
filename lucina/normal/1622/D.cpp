#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}

const int N = 1e5 + 10;
int fac[N];
int inv_fac[N];
void prefact() {
    fac[0] = 1;
    for (int i = 1 ; i < N ; ++ i) fac[i] = mul(fac[i - 1], i);
    inv_fac[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2 ; i >= 0 ; -- i)
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);
}
int C(int n, int r) {
    if (r > n) return 0;
    return 1LL * fac[n] * inv_fac[n - r] % MOD * inv_fac[r] % MOD;
}

const int nax = 1e4 + 10;
int n, k;
char s[nax];
int a[nax];
int sum[nax];

int main() {
    prefact();
    cin >> n >> k;
    cin >> s + 1;
    for (int i = 1 ; i <= n ; ++ i)
        a[i] = s[i] - '0', sum[i] = sum[i - 1] + a[i];
    int ans = 1;
    if (sum[n] < k) return !printf("1");
    for (int l = 1 ; l < n ; ++ l)
    for (int r = l + 1 ; r <= n ; ++ r) {
        int ones = sum[r] - sum[l - 1];
        if (ones > k) continue; /// we can fixed that both end changes, so each changes is tightly bounded to L and R, then count only once
        int z = r - l + 1 - ones;
        if (a[l] == 0) -- ones;
        else -- z;
        if (a[r] == 0) -- ones;
        else -- z;
        if (ones < 0 || z < 0) continue;
       // cout << "C " << ones + z << ' ' << z << " = " << C(ones + z, z) << '\n';
        plusle(ans, C(ones + z, z));
    }
    cout << ans << '\n';
}