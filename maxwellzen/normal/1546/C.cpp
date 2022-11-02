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
vi a, b[2][2];
 
void solve() {
    cin >> n;
    a.rsz(n);
    F0R(i, 2) F0R(j, 2) b[i][j].clear();
    F0R(i, n) {
        cin >> a[i];
        b[0][i%2].pb(a[i]);
    }
    sort(all(a));
    F0R(i, n) {
        b[1][i%2].pb(a[i]);
    }
    F0R(i, 2) F0R(j, 2) sort(all(b[i][j]));
    if (b[0][0]==b[1][0] && b[0][1]==b[1][1]) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}