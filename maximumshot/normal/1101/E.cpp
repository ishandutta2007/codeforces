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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    int mxx = 0;
    int mxy = 0;

    for(int i = 0;i < tt;i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(x > y) swap(x, y);
        if(c == '+') {
            mxx = max(mxx, x);
            mxy = max(mxy, y);
        }else {
            cout << (mxx <= x && mxy <= y ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}