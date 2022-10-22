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

const int N = 105;

int n, x, y;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> x >> y;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    if(x > y) {
        cout << n << "\n";
        return 0;
    }

    int cnt = 0;

    for(int i = 1;i <= n;i++) {
        if(a[i] <= x) cnt++;
    }

    cout << (cnt + 1) / 2 << "\n";

    return 0;
}