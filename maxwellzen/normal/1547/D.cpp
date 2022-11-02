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
vi x, y;
 
void solve() {
    cin >> n;
    x.rsz(n); y.clear(); y.rsz(n, 0);
    F0R(i, n) cin >> x[i];
    FOR(i, 1, n) {
        int prev = x[i-1]^y[i-1];
        // cout << prev << '\n';
        F0R(k, 30) {
            int p = 1<<k;
            // cout << p << ' ' << prev&p << ' ' << x[i]&p << '\n';
            if ((prev&p)>0 && (x[i]&p)==0) {
                y[i] ^= (1<<k);
            }
        }
    }
    F0R(i, n) cout << y[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}