#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<LL> aa(n);
    LL asum = 0;
    for(int i = 0; i < n; i++){
        cin >> aa[i];
        asum += aa[i];
    }
    vector<LL> p(n);
    p[0] = -1;
    for(int i = 1; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<LL> sz(n);
    for(int i = 0; i < n; i++){
        sz[i] = aa[i];
    }
    for(int i = n-1; i > 0; i--){
        sz[p[i]] += sz[i];
    }
    vector<LL> freq(n+1, 0);
    for(int i = 0; i < n; i++){
        LL g = asum / __gcd(asum, sz[i]);
        if(g <= n) freq[g]++;
    }
    vector<LL> tsum(n+1, 0);
    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b += a){
            tsum[b] += freq[a];
        }
    }
    
    const LL MOD = 1000000007;
    
    vector<LL> dp(n+1, 0);
    dp[1] = 1;
    for(int a = 1; a <= n; a++){
        if(tsum[a] != a) dp[a] = 0;
        for(int b = 2*a; b <= n; b += a){
            dp[b] += dp[a];
            dp[b] %= MOD;
        }
    }
    LL ans = 0;
    for(int a = 1; a <= n; a++){
        ans += dp[a];
        ans %= MOD;
    }
    
    cout << ans << '\n';
}