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

int n, fill, sum;
vi a, o, e;
vvi dp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.rsz(n);
    F0R(i, n) {
        cin >> a[i];
        if (a[i]==1) o.pb(i); else e.pb(i);
    }
    dp.rsz(o.size()+1, vi(e.size()+1, 1e9));
    F0R(i, o.size()+1) F0R(j, e.size()+1) {
        if (i==0) dp[i][j]=0;
        else if (i>j) dp[i][j]=1e9;
        else dp[i][j]=min(dp[i][j-1], dp[i-1][j-1]+abs(o[i-1]-e[j-1]));
        // cout << dp[i][j] << ' ';
    }
    cout << dp[o.size()][e.size()] << '\n';
}