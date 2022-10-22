#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int M = 360;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vector< int > cur(M);

    cur[0] = 1;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        vector< int > nxt(M);
        for(int i = 0;i < M;i++) {
            if(cur[i]) {
                nxt[(i + x) % M] = 1;
                nxt[(i - x + M) % M] = 1;
            }
        }
        cur = nxt;
    }

    if(cur[0]) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}