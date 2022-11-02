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
string a, b;

void solve() {
    cin >> a >> b;
    n = a.length();
    F0R(i, n) {
        if (a[i] != b[0]) continue;
        F0R(j, min((int)b.length(), n-i)) {
            if (i+j-(b.length()-j)<0 || a[i+j] != b[j]) continue;
            bool works=true;
            F0R(k, b.length()) {
                if (k<j && a[i+k] != b[k]) {
                    works=false;
                    break;
                }
                if (k >= j && a[i+j-(k-j)] != b[k]) {
                    works=false;
                    break;
                }
            }
            if (works) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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