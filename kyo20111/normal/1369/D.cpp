#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
ll dp[2002002], mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[3] = dp[4] = 4;
    for(int i=4;i<=2000000;i++){
        dp[i] = (i % 3 == 2 ? dp[i-1] + dp[i-2]*2 : dp[i-2] + dp[i-3]*2 + (dp[i-3] + dp[i-4]*2)*2 + 4) % mod;
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
}