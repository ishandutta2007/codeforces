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

    int n, k;

    cin >> n >> k;

    vector< int > a(n);

    for(int &x : a) cin >> x;

    int res = 0;

    for(int b = 0;b < k;b++) {
        vector< int > used(n, 1);
        for(int i = b;i < n;i += k) {
            used[i] = 0;
        }
        int tmp = 0;
        for(int i = 0;i < n;i++) {
            if(used[i]) tmp += a[i];
        }
//        cout << b << " : " << tmp << "\n";
        res = max(res, abs(tmp));
    }

    cout << res << "\n";

    return 0;
}