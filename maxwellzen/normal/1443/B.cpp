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

int t, n, a, b;
string s;
vpi x;
 
void solve() {
    cin >> a >> b >> s;
    x.clear();
    n=s.length();
    int i = 0;
    while (i<n && s[i]=='0') i++;
    while (i<n) {
        pi cur = mp(0, 0);
        while (i<n && s[i]=='1') {
            i++;
            cur.F++;
        }
        while (i<n && s[i]=='0') {
            i++;
            cur.S++;
        }
        x.pb(cur);
    }
    ll ans = 0;
    if (x.size()>1) F0R(j, x.size()-1) ans += min(a, b*x[j].S);
    if (x.size()>0) ans += a;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}