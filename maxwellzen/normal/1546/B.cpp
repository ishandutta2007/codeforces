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

int t, n, m;
vector<string> a, b;
string s;
 
void solve() {
    cin >> n >> m;
    a.clear(); b.clear();
    a.rsz(m);
    b.rsz(m);
    F0R(i, n) {
        cin >> s;
        F0R(j, m) a[j] += s[j];
    }
    F0R(i, n-1) {
        cin >> s;
        F0R(j, m) b[j] += s[j];
    }
    string ans = "";
    F0R(i, m) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        F0R(j, n) {
            if (j==n-1 || a[i][j] != b[i][j]) {
                ans += a[i][j];
                break;
            }
        }
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