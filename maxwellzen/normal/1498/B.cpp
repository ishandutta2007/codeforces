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
int t, n, W;
vi w;

void solve() {
    cin >> n >> W;
    w.rsz(n);
    F0R(i, n) cin >> w[i];
    multiset<int> ws;
    F0R(i, n) ws.insert(w[i]);
    int ans = 0;
    while (ws.size()>0) {
        ans++;
        int cop = W;
        while (ws.upper_bound(cop)!=ws.begin()) {
            auto add = --ws.upper_bound(cop);
            cop -= *add;
            ws.erase(add);
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