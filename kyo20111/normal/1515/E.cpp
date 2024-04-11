#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, mod, dp[404][404];

int add(int a, int b){
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

int mul(int a, int b){
    return (1ll * a * b) % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mod;

    dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = add(dp[i][j], mul(dp[i-1][j-1], j));

            dp[i][j] = add(dp[i][j], mul(dp[i-1][j], 2*j));
            if(i > 1) dp[i][j] = add(dp[i][j], mul(dp[i-2][j], 2*j));

            if(i > 1) dp[i][j] = add(dp[i][j], mul(dp[i-2][j+1], 2*j));
            if(i > 2) dp[i][j] = add(dp[i][j], mul(dp[i-3][j+1], j));
        }
    }

    cout << dp[n][1];
}