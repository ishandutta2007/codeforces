#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[5100][5100];
#define MOD 1000000007
int main(){
    int n;
    cin >> n;
    vector<int> z;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        if(a[0] == 's'){
            z.push_back(0);
        } else {
            z.push_back(1);
        }
    }
    z.push_back(0);
    for(int i = 0; i < 5100; i++){
        for(int j = 0; j < 5100; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < z.size(); i++){
        if(z[i] == 1){
            for(int j = 0; j <= 5000; j++){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        } else {
            for(int j = 5000; j >= 0; j--){
                dp[i+1][j] = dp[i+1][j+1] + dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }
    cout << dp[z.size()-1][0] << endl;
}