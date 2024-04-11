#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }
    if (n == 2){
        cout << max(a[0]+b[1], b[0]+a[1]) << endl;
        return 0;
    }
    int dp[2][n];
    dp[0][0] = b[0];
    dp[1][0] = a[0];
    // 1 to n-1
//  cout << dp[0][0] << " " << dp[1][0] << endl;
    for(int i = 1; i < n-1; i++){
        dp[0][i] = max(dp[0][i-1]+b[i], dp[1][i-1]+c[i]);
        dp[1][i] = max(dp[0][i-1]+a[i], dp[1][i-1]+b[i]);
//      cout << dp[0][i] << " " << dp[1][i] << endl;
    }
    cout << max(dp[0][n-2]+a[n-1], dp[1][n-2]+b[n-1]) << endl;
    
    return 0;
}