#include<bits/stdc++.h>
#define chmin(a, b) a = min(a, b)

using namespace std;
const int inf = 1001001001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> t(n);
        for(int i = 0; i < n; i++) cin >> t[i];
        sort(t.begin(), t.end());
        int base = 200;
        vector<int> dp(402, inf);
        dp[base] = 0;
        int ti = 0;
        for(int i = 0; ti < n; i++) {
            vector<int> ndp(402, inf);
            int cnt = 0;
            while(ti < n && t[ti] == i+1) ++cnt, ++ti;
            for(int j = -200; base + j + cnt <= 401; j++) {
                chmin(ndp[base + j + cnt], dp[base + j] + abs(j));
                chmin(ndp[base + j + cnt - 1], dp[base + j] + abs(j));
            }
            dp = move(ndp);
        }
        for(int j = -200; j < 200; j++) {
            int aj = abs(j);
            chmin(dp[base], dp[base+j] + aj * (aj + 1) / 2);
        }
        cout << dp[base] << '\n';
    }
}