#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll m, b;

    cin >> m >> b;

    ll res = 0;

    for(ll tmp, y, x = 0;x <= m * b;x++) {
        y = (m * b - x) / m;
        tmp = (y + 1) * x * (x + 1) / 2 + (x + 1) * y * (y + 1) / 2;
        if(res < tmp) res = tmp;
    }

    cout << res << "\n";

    return 0;
}