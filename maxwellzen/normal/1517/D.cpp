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

int n, m, k;
vvi r, d;
vector<vvll> dp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    r.rsz(n, vi(m-1));
    d.rsz(n-1, vi(m));
    F0R(i, n) F0R(j, m-1) cin >> r[i][j];
    F0R(i, n-1) F0R(j, m) cin >> d[i][j];
    if (k%2!=0) {
        F0R(i, n) {
            F0R(j, m) cout << -1 << ' ';
            cout << '\n';
        }
        return 0;
    }
    k /= 2;
    dp.rsz(k+1, vvll(n, vll(m, 0)));
    FOR(step, 1, k+1) {
        F0R(i, n) F0R(j, m) {
            ll ans = LLONG_MAX;
            if (i>0) ans=min(ans, dp[step-1][i-1][j]+2*d[i-1][j]);
            if (i<n-1) ans=min(ans, dp[step-1][i+1][j]+2*d[i][j]);
            if (j>0) ans=min(ans, dp[step-1][i][j-1]+2*r[i][j-1]);
            if (j<m-1) ans=min(ans, dp[step-1][i][j+1]+2*r[i][j]);
            FOR(s, 1, step) ans=min(ans, dp[s][i][j]+dp[step-s][i][j]);
            dp[step][i][j]=ans;
        }
    }
    F0R(i, n) {
        F0R(j, m) cout << dp[k][i][j] << ' ';
        cout << '\n';
    }
}