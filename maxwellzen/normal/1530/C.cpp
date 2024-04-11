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
vll a, b;
 
void solve() {
    cin >> n;
    a.rsz(n); b.rsz(n);
    F0R(i, n) cin >> a[i]; F0R(i, n) cin >> b[i];
    sort(all(a)); reverse(all(a)); sort(all(b)); reverse(all(b));
    FOR(i, 1, n) a[i] += a[i-1]; FOR(i, 1, n) b[i] += b[i-1];
    FOR(i, 0, 3*n+1) {
        ll asum=100*i, bsum=0;
        int k = n+i, bn = k - (k/4), an = bn-i;
        if (an>0) asum += a[min(n-1, an-1)];
        if (bn>0) bsum += b[min(n-1, bn-1)];
        if (asum >= bsum) {
            cout << i << '\n';
            return;
        }
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