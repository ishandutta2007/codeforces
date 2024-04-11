#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        vector <vector <int> > colored(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            colored[a[i]].push_back(i);
        }
        vector <vector <int> > dp(n, vector <int> (n, 0));
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j];
                for(auto k : colored[a[i]]){
                    if(k <= i || k > j){
                        continue;
                    }
                    dp[i][j] = max(dp[i][j], dp[i + 1][k - 1] + 1 + dp[k][j]);
                }
            //    cout << dp[i][j] << " ";
            }
            //cout << "\n";
        }
        cout << n -1 - dp[0][n - 1] << "\n";
    }
    return 0;
}