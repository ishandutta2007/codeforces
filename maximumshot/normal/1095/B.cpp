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

    int n;
    cin >> n;

    vector< int > a(n);

    for(int &x : a) cin >> x;

    int res = inf;

    multiset< int > q;

    for(int x : a) q.insert(x);

    for(int x : a) {
        q.erase(q.lower_bound(x));
        res = min(res, *(--q.end()) - *q.begin());
        q.insert(x);
    }

    cout << res << "\n";

    return 0;
}