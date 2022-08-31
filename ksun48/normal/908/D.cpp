#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 1000000007
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}

LL dp[1100][1100];

int main(){
    for(int i = 0; i < 1100; i++){
        for(int j = 0; j < 1100; j++){
            dp[i][j] = 0;
        }
    }
    int k;
    LL pa, pb;
    cin >> k >> pa >> pb;
    LL sum = pa + pb;
    pa = (pa * inv(sum)) % MOD;
    pb = (pb * inv(sum)) % MOD;
    LL ipa = inv(pa);
    LL ipb = inv(pb);

    LL frac = (pa * ipb) % MOD;

    for(int na = k; na >= 0; na--){
        for(int ns = k; ns >= 0; ns--){
            if(na == 0){
                dp[na][ns] = dp[na+1][ns];
            } else if(na == k){
                dp[na][ns] = ns + k + frac;
                dp[na][ns] %= MOD;
            } else {
                dp[na][ns] = dp[na+1][ns] * pa;
                if(na + ns >= k){
                    dp[na][ns] += (na + ns) * pb;
                } else {
                    dp[na][ns] += dp[na][na+ns] * pb;
                }
                dp[na][ns] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
}