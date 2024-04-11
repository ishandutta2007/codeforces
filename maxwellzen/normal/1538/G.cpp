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
ll x, y, a, b, diff;
 
void solve() {
    cin >> x >> y >> a >> b;
    if (a==b) {
        cout << min(x/a, y/a) << '\n';
        return;
    }
    if (a>b) swap(a, b);
    if (x>y) swap(x, y);
    diff = b-a;
    ll l=1, r=(x+y)/(a+b), ans=0;
    while (l <= r) {
        int m = (l+r)/2;
        if (x>=a*m && y>=a*m && (x-a*m)/diff + (y-a*m)/diff >= m) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
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