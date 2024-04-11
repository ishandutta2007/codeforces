#include <bits/stdc++.h>
using namespace std; 

const int maxN = 4000 + 10;
int dp[maxN];
int main() {
    memset( dp , -63, sizeof dp );
    dp[0] = 0;
    int n; cin >> n;
    for( int t = 0; t < 3 ; t++ ) { 
        int a; cin >> a;
        for( int i = a ; i <= n ; i++ ) 
            dp[i] = max( dp[i] , 1 + dp[i-a]);
    }
    cout << dp[n] << endl;
}