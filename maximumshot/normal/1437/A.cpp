#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;
        int ok = 0;

        for (ll a = 1; a <= 40000; a++) {
            ll k = (r + a) / a;
            if (k > 0 && a * (2 * k - 1) <= 2 * l) {
                ok = 1;
                break;
            }
        }

        for (ll k = 1; k <= 40000; k++) {
            ll a = (r + k) / k;
            if (a > 0 && a * (2 * k - 1) <= 2 * l) {
                ok = 1;
                break;
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}