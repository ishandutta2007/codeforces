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

int n, x;
ll MOD = 998244353, ans;
vll a, two;
char c;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.rsz(n);
    F0R(i, n) {
        cin >> c;
        if (c=='-') a[i]=0;
        else cin >> a[i];
    }
    two.rsz(n+1);
    two[0]=1;
    FOR(i, 1, n+1) two[i]=(2*two[i-1])%MOD;
    ans=0;
    F0R(i, n) if (a[i]>0) {
        // cout << "dp on " << a[i] << endl;
        vll dp(n+1, 0);
        dp[0]=1;
        F0R(j, n) {
            if (a[j]==0) {
                if (j<i) dp[0]=(2*dp[0])%MOD;
                F0R(k, n) dp[k] = (dp[k]+dp[k+1])%MOD;
            }
            else {
                if (a[j]<a[i] || (a[j]==a[i] && j<i)) R0F(k, n) dp[k+1] = (dp[k+1]+dp[k])%MOD;
                else if (j != i) F0R(k, n+1) dp[k]=(2*dp[k])%MOD;
            }
            // F0R(k, n+1) cout << dp[k] << ' '; cout << endl;
        }
        F0R(j, n+1) ans = (ans + a[i]*dp[j])%MOD;
    }
    cout << ans << endl;
}