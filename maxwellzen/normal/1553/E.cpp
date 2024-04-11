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

int t, n, m;
vi a, freq;

void solve() {
    cin >> n >> m;
    a.rsz(n); freq.clear(); freq.rsz(n, 0);
    F0R(i, n) {cin >> a[i]; a[i]--; freq[(i-a[i]+n)%n]++;}
    vi ans;
    F0R(d, n) {
        if (n - 2*m <= freq[d]) {
            int cnt = 0;
            vb vis(n, false);
            F0R(i, n) {
                if (vis[i]) continue;
                if ((a[i]+d)%n==i) continue;
                int cyc=1, cpy=(a[i]+d)%n;
                while (cpy != i) {
                    vis[cpy]=true;
                    cyc++;
                    cpy = (a[cpy]+d)%n;
                }
                vis[i]=true;
                cnt += cyc-1;
            }
            if (cnt <= m) ans.pb(d);
        }
    }
    cout << ans.size();
    F0R(i, ans.size()) cout << ' ' << ans[i];
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}