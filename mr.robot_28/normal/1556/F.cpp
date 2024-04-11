#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 1e9 + 7;
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int t = power(a, b / 2);
        return 1LL * t * t % mod;
    }
    return 1LL * a * power(a, b - 1) % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <vector <ll> > hp(n, vector <ll> (n));
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            hp[i][j] = power(a[i] + a[j], mod - 2);
        }
    }
    vector <ll> dp(1 << n);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        dp[1 << i] = 1;
    }
    for(int msk = 1; msk < (1 << n); msk++){
        dp[msk] = 1;
        for(int j = msk; j >= 0; j = (j - 1) & msk)
        {
            int msk1 = msk - j;
            if(j == 0){
                break;
            }
            if(msk1 != 0){
            ll s = dp[j] % mod;
            for(int t = 0; t < n; t++){
                if(((1 << t) & j) == 0){
                    continue;
                }
                for(int t1 = 0; t1 < n; t1++){
                    if(((1 << t1) & msk1) == 0){
                        continue;
                    }
                    s = (s * a[t]) % mod * hp[t][t1] % mod;
                }
            }
     //           cout << msk1 << " " << j << " " << s << " " << hp[0][1] << "\n";
            dp[msk] = (dp[msk] + mod - s) % mod;
            }
        }
    }
   // cout << 1LL * hp[0][1] * 3 % mod << "\n";
   // cout << dp[1] << " " << dp[2] << " " << dp[3] << "\n";
    ll ans = 0;
    for(int j = 1; j < (1 << n); j++){
        ll s = 1LL * dp[j] * __builtin_popcount(j) % mod;
        for(int t = 0; t < n; t++){
            if(((1 << t) & j) == 0){
                continue;
            }
            for(int t1 = 0; t1 < n; t1++){
                if(((1 << t1) & j) != 0){
                    continue;
                }
                s = s * a[t] % mod * hp[t][t1] % mod;
            }
        }
        ans = (ans + s) % mod;
    }
    cout << ans;
    return 0;
}