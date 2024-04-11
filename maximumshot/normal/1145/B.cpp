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

    int u[20] = {0};
    int d[10] = {0};

    u[0] = 1;
    u[2] = 1;
    u[3] = 1;
    u[4] = 1;
    u[5] = 1;
    u[6] = 1;
    u[8] = 1;
    u[12] = 1;
    d[3] = 1;
    d[4] = 1;
    d[5] = 1;
    d[6] = 1;
    d[8] = 1;

    int x;

    cin >> x;

    if (x < 20) {
        cout << (u[x] ? "YES" : "NO") << "\n";
    } else {
        cout << (u[x % 10] & d[x / 10] ? "YES" : "NO") << "\n";
    }

    return 0;
}