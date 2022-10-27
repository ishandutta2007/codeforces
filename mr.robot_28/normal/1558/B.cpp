#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

const int N = 1e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> dp(n + 1);
    vector <int> bal(n + 1);
    dp[1] = 1;
    int s = 0;
    for(int i = 1; i < n; i++){ 
        s = (s + bal[i]) % m;
        dp[i] = (dp[i] + s) % m;
        s = (s + dp[i]) % m;
        for(int j = 2; j * i <= n; j++){
            bal[i * j] = (bal[j * i] + dp[i]) % m;
            if(i * j + j <= n){
                bal[i * j + j] = (bal[j * i + j] + m - dp[i]) % m;
            }
        }
    }
    cout << (dp[n] + s + bal[n]) % m;
    return 0;
}