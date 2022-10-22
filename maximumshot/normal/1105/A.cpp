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

    int tt = -1;
    int bb = inf;

    for(int t = 1;t <= 100;t++) {
        int sc = 0;
        for(int x : a) {
            if(x == t) continue;
            if(x > t) sc += x - t - 1;
            else sc += t - x - 1;
        }
        if(sc < bb) {
            bb = sc;
            tt = t;
        }
    }

    cout << tt << " " << bb << "\n";

    return 0;
}