#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dp[11][11][11];
string s;

void solve(){
    memset(dp, 0, sizeof dp);
    cin >> s;

    dp[0][0][0] = 1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) for(int k=0;k<10;k++){
            if(s[i] == '1' || s[i] == '?'){
                if(i % 2) dp[i+1][j][k+1] |= dp[i][j][k];
                else dp[i+1][j+1][k] |= dp[i][j][k];
            }
            if(s[i] == '0' || s[i] == '?') dp[i+1][j][k] |= dp[i][j][k];
        }
    }

    for(int i=1;i<10;i++){
        int al = 5 - (i+1)/2, bl = 5 - i/2;

        for(int j=0;j<10;j++) for(int k=0;k<10;k++) if(dp[i][j][k] && (j+al < k || k+bl < j)){
            cout << i;
            return;
        }
    }
    cout << 10;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}