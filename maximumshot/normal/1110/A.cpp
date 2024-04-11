#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, k;

    cin >> b >> k;

    int res = 0;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            if(i + 1 < k) {
                res += b;
            } else {
                res++;
            }
        }
        res &= 1;
    }

    cout << (res ? "odd" : "even") << "\n";

    return 0;
}