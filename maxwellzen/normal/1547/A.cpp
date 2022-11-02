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

int t;
pi a, b, c;
 
void solve() {
    cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S;
    if (a.F != b.F && a.S != b.S) {
        cout << abs(a.F-b.F)+abs(a.S-b.S) << '\n';
        return;
    } else {
        if (c.F <= max(a.F, b.F) && c.F >= min(a.F, b.F) && c.S <= max(a.S, b.S) && c.S >= min(a.S, b.S)) {
            cout << abs(a.F-b.F)+abs(a.S-b.S)+2 << '\n';
        } else cout << abs(a.F-b.F)+abs(a.S-b.S) << '\n';
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