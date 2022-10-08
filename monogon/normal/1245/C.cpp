
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, M = 1'000'000'007;
string s;
int n;
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    for(char c : s) {
        if(c == 'm' || c == 'w') {
            cout << 0 << endl;
            return 0;
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        if((s[i - 1] == 'n' || s[i - 1] == 'u') && s[i - 1] == s[i - 2]) {
            dp[i] = (dp[i] + dp[i - 2]) % M;
        }
    }
    cout << dp[n] << endl;
}