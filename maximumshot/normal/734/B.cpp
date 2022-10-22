#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    ll k2, k3, k5, k6;

    cin >> k2 >> k3 >> k5 >> k6;

    ll res = 0;

    for(ll t1, t2, y, x = 0;x <= k2;x++) {
        y = k2 - x;
        t1 = min({k3, x});
        t2 = min({y, k5, k6});
        res = max(res, t1 * 32 + t2 * 256);
    }

    cout << res << "\n";

    return 0;
}