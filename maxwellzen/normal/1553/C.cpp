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

int t, n, amx, amn, bmx, bmn;
string s;

void solve() {
    cin >> s;
    n = 10;
    amx=amn=bmx=bmn=0;
    F0R(i, n) {
        if (i%2==0) {
            if (s[i]=='0') amn++;
            if (s[i]=='1') amx++;
            if (s[i]=='?') {
                amn++;
                amx++;
            }
        } else {
            if (s[i]=='0') bmn++;
            if (s[i]=='1') bmx++;
            if (s[i]=='?') {
                bmn++;
                bmx++;
            }
        }
        if (i==n-1 || amx > (5-bmn) || bmx > (5-amn)) {
            cout << i+1 << '\n';
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