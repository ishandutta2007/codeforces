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

int t, n, mx, mn;
vi b;
set<int> a;
 
void solve() {
    cin >> n;
    b.rsz(n);
    F0R(i, n) cin >> b[i];
    a.clear();
    a.insert(b[0]);
    mx=mn=b[0];
    FOR(i, 1, n) {
        if (b[i]==b[i-1]) continue;
        a.insert(b[i]);
        mx=max(b[i], mx);
        mn=min(b[i], mn);
        if ((b[i]==mx || *++a.find(b[i]) != b[i-1]) 
        && (b[i]==mn || *--a.find(b[i]) != b[i-1])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}