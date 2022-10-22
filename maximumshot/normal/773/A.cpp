#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int t;

    cin >> t;

    while(t--) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        if(p == 0) {
            if(x == 0) {
                cout << "0\n";
            }else {
                cout << "-1\n";
            }
        }else if(p == q) {
            if(x == y) {
                cout << "0\n";
            }else {
                cout << "-1\n";
            }
        }else {
            ll t = max((x + p - 1) / p, (y - x + q - p - 1) / (q - p));
            cout << t * q - y << "\n";
        }
    }

    return 0;
}