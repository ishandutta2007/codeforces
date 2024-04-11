#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int t, n;

void solve() {
    int W, H, x1, x2, y1, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int ans = 1e9;
    if (w+abs(x1-x2)>W && h+abs(y1-y2)>H) {
        cout << -1 << '\n';
        return;
    }
    if (w+abs(x1-x2)<=W) {
        ans = min(ans, max(0, w-min(x1, x2)));
        ans = min(ans, max(0, max(x1, x2)-(W-w)));
    }
    if (h+abs(y1-y2)<=H) {
        ans = min(ans, max(0, h-min(y1, y2)));
        ans = min(ans, max(0, max(y1, y2)-(H-h)));
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