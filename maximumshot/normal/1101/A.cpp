#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int q;

    cin >> q;

    while(q--) {
        int l, r, d;
        cin >> l >> r >> d;
        if(d < l) {
            cout << d << "\n";
        }else {
            int res = max(1, r/d) * d;
            while(res <= r) res += d;
            cout << res << "\n";
        }
    }

    return 0;
}