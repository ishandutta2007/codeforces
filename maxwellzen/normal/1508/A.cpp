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

int t, n;
string s[3];
int cnt[3][2];

string calc(int i, int j, int b) {
    if (cnt[i][b]>cnt[j][b]) swap(i, j);
    vi loc[2];
    F0R(k, 2*n) {
        if (s[i][k]-'0'==b) loc[0].pb(k);
        if (s[j][k]-'0'==b) loc[1].pb(k);
    }
    while (loc[1].size()>loc[0].size()) loc[1].erase(--loc[1].end());
    loc[0].pb(2*n); loc[1].pb(2*n);
    string ans = s[i].substr(0, loc[0][0])+s[j].substr(0, loc[1][0]);
    F0R(k, loc[0].size()-1) {
        ans += (char)('0'+b);
        ans += s[i].substr(loc[0][k]+1, loc[0][k+1]-loc[0][k]-1);
        ans += s[j].substr(loc[1][k]+1, loc[1][k+1]-loc[1][k]-1);
    }
    return ans;
}
 
void solve() {
    cin >> n;
    F0R(i, 3) {
        cin >> s[i];
        cnt[i][0]=cnt[i][1]=0;
        F0R(j, 2*n) if (s[i][j]=='0') cnt[i][0]++; else cnt[i][1]++;
    }
    F0R(j, 3) F0R(i, j) F0R(b, 2) if (cnt[i][b]>=n && cnt[j][b]>=n) {
        cout << calc(i, j, b) << '\n';
        return;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}