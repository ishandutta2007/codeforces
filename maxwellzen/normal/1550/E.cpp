#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int t, n, k, m;
string s;
vvi pref;

bool eval() {
    vvi loc(k);
    F0R(i, k) {
        F0R(j, n-m+1) if (pref[j+m][i]+pref[j+m][k]-pref[j][i]-pref[j][k]==m) loc[i].pb(j);
    }
    vi dp(1<<k, 1e9);
    dp[0]=0;
    FOR(i, 1, 1<<k) {
        F0R(j, k) if (i&(1<<j)) {
            int pre = i^(1<<j);
            if (dp[pre]==1e9) continue;
            if (lower_bound(all(loc[j]), dp[pre])==loc[j].end()) continue;
            dp[i]=min(dp[i], (*lower_bound(all(loc[j]), dp[pre]))+m);
        }
    }
    return dp[(1<<k)-1]<1e9;
}
 
void solve() {
    cin >> n >> k >> s;
    pref.rsz(n+1, vi(k+1, 0));
    F0R(i, n) {
        F0R(j, k+1) pref[i+1][j]=pref[i][j];
        if (s[i]=='?') pref[i+1][k]++; else pref[i+1][s[i]-'a']++;
    }
    int l=1, r=n/k, ans=0;
    while (l <= r) {
        m = (l+r)/2;
        if (eval()) {
            ans=m;
            l=m+1;
        } else r=m-1;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}