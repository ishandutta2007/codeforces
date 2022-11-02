#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

const int mx = 1e9+10;

int n, g, u;
vpi nums;
vi dp, ans, pre;
set<pi> sofar;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    nums.rsz(n);
    ans.rsz(n);
    pre.rsz(n+1);
    F0R(i, n) cin >> nums[i].F;
    F0R(i, n) nums[i].S=i;
    sort(all(nums));
    dp.rsz(n+1, mx);
    dp[0]=0;
    sofar.insert(mp(0-nums[0].F,0));
    pre[0]=0;
    for (int i = 3; i <= n; i++) {
        int j = sofar.begin()->S;
        dp[i]=dp[j]+nums[i-1].F-nums[j].F;
        pre[i]=j;
        sofar.insert(mp(dp[i-2]-nums[i-2].F, i-2));
    }
    g=1, u=pre[n];
    for (int i = n-1; i >= 0; i--) {
        ans[nums[i].S]=g;
        if (i==u) {
            g++;
            u=pre[u];
        }
    }
    cout << dp[n] << ' ' << g-1 << '\n';
    F0R(i, n) cout << ans[i] << ' ';
    cout << '\n';
}