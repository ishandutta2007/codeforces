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

const int N = 3e5 + 5;

int n;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    ll tr = 0;
    for (int i = 0; i < n; i++) {
        ll cn = min(tr, a[i] / 2ll);
        res += cn;
        tr -= cn;
        a[i] -= 2 * cn;
        res += a[i] / 3;
        a[i] %= 3;
        tr += a[i];
    }

    cout << res << "\n";

    return 0;
}