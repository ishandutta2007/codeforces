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
vi a;

bool cmp(int a, int b) {
    int ta=0, tb=0;
    while (a%2==0) {a/=2; ta++;}
    while (b%2==0) {b/=2; tb++;}
    return ta>tb;
}
 
void solve() {
    cin >> n;
    a.clear(); a.rsz(n);
    F0R(i, n) cin >> a[i];
    sort(all(a), cmp);
    int ans = 0;
    F0R(j, n) F0R(i, j) if (__gcd(a[i], 2*a[j])>1) ans++;
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