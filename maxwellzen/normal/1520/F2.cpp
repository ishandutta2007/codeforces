#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

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

int t, n, k;
map<pi, int> qs;

void upd(int i, int l, int r) {
    if (l>=r) return;
    int m = (l+r)/2;
    if (i <= m) {
        qs[mp(l, m)]--;
        upd(i, l, m);
    } else {
        qs[mp(m+1, r)]--;
        upd(i, m+1, r);
    }
}

void solve() {
    cin >> k;
    int l=0, r=n-1;
    while (l<r) {
        int m = (l+r)/2;
        pi p = mp(l, m);
        if (qs.find(p)==qs.end()) {
            cout << "? " << l+1 << ' ' << m+1 << endl;
            cin >> qs[p];
            qs[p]=m-l+1-qs[p];
        }
        if (qs[p]>=k) r=m;
        else {
            k -= qs[p];
            l=m+1;
        }
    }
    cout << "! " << l+1 << endl;
    upd(l, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    while (t--) {
        solve();
    }
}
// 1 0 1 1 0 1
// 0 0 0 1