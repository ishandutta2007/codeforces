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
vi a;
set<int> s;

void solve() {
    s.clear();
    cin >> n;
    a.rsz(n);
    F0R(i, n) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    s.insert(0);
    int sum = 0;
    F0R(i, n) {
        if (s.count(a[i])) {
            cout << "YES\n";
            return;
        }
        sum += a[i];
    }
    vb dp(sum+1, false);
    dp[0]=true;
    F0R(i, n) {
        ROF(j, a[i], dp.size()) {
            if (dp[j-a[i]]) {
                if (dp[j]) {
                    cout << "YES\n";
                    return;
                }
                dp[j]=true;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}