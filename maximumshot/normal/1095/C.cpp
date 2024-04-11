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

    if(__builtin_popcount(n) > k || k > n) {
        cout << "NO\n";
        return 0;
    }

    multiset< int > q;

    for(int j = 0;j <= 30;j++) {
        if((1 << j) & n) {
            q.insert(1 << j);
            k--;
        }
    }

    while(k > 0) {
        int x = *(--q.end());
        q.erase(--q.end());
        k--;
        q.insert(x / 2);
        q.insert(x / 2);
    }

    cout << "YES\n";

    for(int x : q) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}