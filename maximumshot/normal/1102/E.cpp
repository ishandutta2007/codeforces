#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = 998244353;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    map< int, int > le, ri;
    vector< int > a(n);
    set< int > vals;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        vals.insert(a[i]);
        int x = a[i];
        if(!le.count(x)) {
            le[x] = i;
        }
        ri[x] = i;
    }

    vector< pii > segs;

    for(int x : vals) {
//        if(le[x] == ri[x]) continue;
        segs.push_back({le[x], ri[x]});
    }

    if(segs.empty()) {
        vector< int > f(n + 1);
        f[1] = 1;
        for(int i = 2;i <= n;i++) {
            f[i] = (f[i - 1] * 2ll) % mod;
        }
        cout << f[n] << "\n";
        return 0;
    }

    vector< pii > ar;

    sort(segs.begin(), segs.end());

    for(pii p : segs) {
        if(ar.empty()) {
            ar.push_back(p);
            continue;
        }
        if(p.first > ar.back().second) {
            ar.push_back(p);
            continue;
        }
        ar.back().second = max(ar.back().second, p.second);
    }

    int res = 1;
    int last = 0;

    for(pii p : ar) {
//        cout << p.first << " " << p.second << "\n";
        res = (1ll * res * (p.first - last + 1)) % mod;
        last = p.second;
    }

    res = (1ll * res * (n - ar.back().second)) % mod;

    cout << res << "\n";

    return 0;
}