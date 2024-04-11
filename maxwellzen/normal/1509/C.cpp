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

int n;
vi s;
vvll dp;

ll rec(int l, int r) {
    if (l==r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r]=min(rec(l+1, r), rec(l, r-1))+s[r]-s[l];
    return dp[l][r];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s.rsz(n);
    F0R(i, n) cin >> s[i];
    sort(all(s));
    dp.rsz(n, vll(n, -1));
    cout << rec(0, n-1) << '\n';
}