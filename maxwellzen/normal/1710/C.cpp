#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
const ll MOD = 998244353;

int n;
string s;

void solve() {
    cin >> s;
    n = s.size();

    // dp[i][j][k] -> how many ways to set i bits such that subset j has been "freed", and subset k has received a minority bit
    ll dp[n+1][8][8];
    fill(*dp[0], *dp[n+1], 0);

    // default state: 0 bits set, none have been "freed", and none have received a minority bit
    dp[0][0][0] = 1;

    F0R(i, n) F0R(j, 8) F0R(k, 8) F0R(mask, 8)
        if (s[i]=='1' || (mask&j)==mask) {
            // if current bit is 1, the zero-bits in the current mask have been freed
            int nj = j;
            if (s[i]=='1') nj |= 7&~mask;
            // add minority bits
            int nk = k;
            if (__builtin_popcount(mask)==1) nk |= mask;
            if (__builtin_popcount(mask)==2) nk |= 7&~mask;
            // add previous state to new state
            dp[i+1][nj][nk] = (dp[i+1][nj][nk] + dp[i][j][k])%MOD;
        }
        
    ll ans = 0;
    F0R(i, 8) ans = (ans + dp[n][i][7])%MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}