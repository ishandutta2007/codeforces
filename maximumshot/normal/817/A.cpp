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

//

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    ll x, y;

    cin >> x >> y;

    if((x2 - x1) % x) {
        cout << "NO\n";
        return 0;
    }

    ll k = (x2 - x1) / x;

    x1 += k * x;
    y1 += k * y;

    if((y2 - y1) % y) {
        cout << "NO\n";
        return 0;
    }

    k = (y2 - y1) / y;

    if( (k >= 0 ? k : -k) % 2 ) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }

    return 0;
}