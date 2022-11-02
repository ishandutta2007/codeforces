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
int t, n, u, v;
vi w;
vi deg;

void solve() {
    cin >> n;
    w.rsz(n+1);
    F0R(i, n) cin >> w[i+1];
    deg.clear();
    deg.rsz(n+1, 0);
    FOR(i, 1, n) {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    multiset<int> toadd;
    FOR(i, 1, n+1) {
        FOR(j, 1, deg[i]) {
            toadd.insert(w[i]);
        }
    }
    ll sum = 0;
    FOR(i, 1, n+1) {
        sum += w[i];
    }
    FOR(i, 0, n-1) {
        cout << sum << ' ';
        if (i < n-2) {
            sum += *--toadd.end();
            toadd.erase(--toadd.end());
        }
    }
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