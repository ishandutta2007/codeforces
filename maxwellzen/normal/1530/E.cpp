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
string s;
map<char, int> freq;
vector<pair<char, int>> v;

void solve() {
    v.clear(); freq.clear();
    cin >> s;
    n = s.length();
    F0R(i, n) freq[s[i]]++;
    if (freq.size()==1) {
        cout << s << '\n';
        return;
    }
    bool one = false;
    char only;
    for (auto p : freq) {
        if (p.S==1) {
            one=true;
            only = p.F;
            break;
        }
        v.pb(p);
    }
    if (one) {
        string ans = "";
        ans += only;
        for (auto p : freq) if (p.F != only) F0R(i, p.S) ans += p.F;
        cout << ans << '\n';
        return;
    }
    string ans = "";
    ans += v[0].F;
    v[0].S--;
    if ((v[0].S - 1)*2 <= n-2) {
        ans += v[0].F;
        v[0].S--;
        string extra = "";
        FOR(i, 1, v.size()) F0R(j, v[i].S) extra += v[i].F;
        F0R(i, extra.length()) {
            ans += extra[i];
            if (v[0].S>0) {
                ans += v[0].F;
                v[0].S--;
            }
        }
        cout << ans << '\n';
        return;
    }
    if (v.size()==2) {
        F0R(i, v[1].S) ans += v[1].F;
        F0R(i, v[0].S) ans += v[0].F;
        cout << ans << '\n';
        return;
    }
    ans += v[1].F; v[1].S--;
    F0R(i, v[0].S) ans += v[0].F;
    ans += v[2].F; v[2].S--;
    F0R(i, v[1].S) ans += v[1].F;
    FOR(i, 2, v.size()) F0R(j, v[i].S) ans += v[i].F;
    cout << ans << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}