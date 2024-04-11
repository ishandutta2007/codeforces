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
        ll n;
        cin >> n;
        int ok = 0;
        for (ll x = 1; x <= 6; x++) {
            if (21 - x <= n && (n - (21 - x)) % 14 == 0) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}