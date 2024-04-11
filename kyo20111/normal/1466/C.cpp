#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[2][30][30];
string s;

void solve_tc(){
    cin >> s;
    int n = s.size();
    for(int i=0;i<=1;i++) for(int j=0;j<=27;j++) for(int k=0;k<=27;k++) dp[i][j][k] = 1e9;

    dp[0][0][1] = 0;
    for(int i=1;i<=n;i++){
        int u = s[i-1] - 'a' + 2;

        for(int j=0;j<=27;j++) for(int k=0;k<=27;k++) dp[i%2][j][k] = 1e9;

        for(int j=0;j<=27;j++){
            for(int k=0;k<=27;k++) if(j != k){
                if(j != u && k != u) dp[i%2][k][u] = min(dp[i%2][k][u], dp[!(i%2)][j][k]);
                dp[i%2][k][0] = min(dp[i%2][k][0], dp[!(i%2)][j][k] + 1);
                dp[i%2][k][1] = min(dp[i%2][k][1], dp[!(i%2)][j][k] + 1);
            }
        }
    }

    int ans = 1e9;
    for(int i=0;i<=27;i++) for(int j=0;j<=27;j++) ans = min(ans, dp[n%2][i][j]);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        cout << "\n";
    }
}