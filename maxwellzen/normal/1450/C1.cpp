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
vector<string> s;

void solve() {
    cin >> n;
    s.rsz(n);
    F0R(i, n) cin >> s[i];
    vi cnt(3, 0);
    F0R(i, n) F0R(j, n) if (s[i][j]=='X') cnt[(i+j)%3]++;
    int ch = 0;
    F0R(i, 3) if (cnt[i]<cnt[ch]) ch=i;
    F0R(i, n) F0R(j, n) if ((i+j)%3==ch && s[i][j]=='X') s[i][j]='O';
    F0R(i, n) cout << s[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}