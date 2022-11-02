#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
int t, n, a[101], b[101], tim[101];

void solve() {
    cin >> n;
    F0R(i, n) cin >> a[i] >> b[i];
    F0R(i, n) cin >> tim[i];
    int cur = a[0];
    F0R(i, n) {
        if (i==0) cur = a[0]+tim[0];
        else cur = cur + a[i] - b[i-1] + tim[i];
        if (i<n-1) cur = max(cur+ (b[i]-a[i]+1)/2, b[i]);
    }
    cout << cur << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}