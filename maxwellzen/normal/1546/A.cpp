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
vi a, b;
vi add, subtract;
 
void solve() {
    cin >> n;
    a.rsz(n); b.rsz(n); add.clear(); subtract.clear();
    F0R(i, n) cin >> a[i];
    F0R(i, n) cin >> b[i];
    F0R(i, n) {
        if (a[i]<b[i]) FOR(j, a[i], b[i]) add.pb(i);
        else if (a[i]>b[i]) FOR(j, b[i], a[i]) subtract.pb(i);
    }
    if (add.size() != subtract.size()) cout << -1 << '\n';
    else {
        cout << add.size() << '\n';
        F0R(i, add.size()) cout << subtract[i]+1 << ' ' << add[i]+1 << '\n';
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