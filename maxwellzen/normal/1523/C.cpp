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
vi a, cur;
 
void solve() {
    cin >> n;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    cur.clear();
    F0R(i, n) {
        if (a[i]==1) cur.pb(1);
        else {
            while (a[i] != cur[cur.size()-1]+1) cur.pop_back();
            cur.pop_back();
            cur.pb(a[i]);
        }
        F0R(j, cur.size()-1) cout << cur[j] << '.';
        cout << cur[cur.size()-1] << '\n';
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