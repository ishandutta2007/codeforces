#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int const nax = 2e5 + 10;
 
 
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
const int MX = 2e5 + 10;
int fac[MX], invf[MX] ;
void prefact() {
    fac[0] = 1 ;
    for (int i = 1 ; i < MX ; i ++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invf[MX - 1] = power(fac[MX - 1], mod - 2);
    for (int i = MX - 2 ; i >= 0 ; i --) {
        invf[i] = mul(invf[i + 1], i + 1);
    }
}
 
int ncr (int N, int R) {
    if (R > N || R < 0) return 0;
    if (R == 0 || R == N) return 1;
    return mul(fac[N], mul(invf[N - R], invf[R]));
}
 
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
 
    int s = min(-l + 1, r - n); /// the range that all number can be either negative or positive
    int ans = mul(ncr(n, n / 2), s);
    if (n % 2) ans = mul(ans, 2);
    for (++ s ; ; ++ s) {
        int a = max(0, s + l - 1);/// number that can only be positive
        int b = max(0, n + s - r);/// number that can only be negative
 
        if (a > (n + 1) / 2 || b > (n + 1) / 2) break;
        int res = ncr(n - a - b, n / 2 - a);
        if (n % 2) res = add(res, ncr(n - a - b, n / 2 - b));
        plusle(ans, res);
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
}