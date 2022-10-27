#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int nax = 2e5 + 10;
int n, p;
int a[nax];
int dp[nax];
int s[nax];

int main() {

    dp[0] = 1;
    dp[1] = 1;
    s[1] = 2, s[0] = 1;
    for (int i = 2 ; i < nax ; ++ i) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
        s[i] = add(s[i - 1], dp[i]);
    }
    cin >> n >> p;
    set <int> first;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        first.insert(a[i]);
    }
    int ans = 0;
    set <int> s;
    for (int i = 1 ; i <= n ; ++ i) {
        int x = a[i];
        bool bad = false;
        while (x > 1) {
            bool j = false;
            while (x % 4 == 0) {
                x /= 4;
                if (first.count(x)) bad = true;
                j = true;
            }
            while (x % 2 == 1 && x > 1) {
                x /= 2;
                if (first.count(x)) bad = true;;
                j = true;
            }
            if (!j) break;
        }
        if (!bad) s.insert(a[i]);
    }


    for (int x : s) {
        int cnt = 32 - __builtin_clz(x);
        int rem = p - cnt;
        if (rem < 0) continue;
        ans = add(ans, ::s[rem]);
    }
    cout << ans << '\n';


}