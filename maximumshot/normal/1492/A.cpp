#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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
        ll p, a, b, c;
        cin >> p >> a >> b >> c;

        auto f = [&](ll k) -> ll {
            return k * ((p + k - 1) / k);
        };

        ll res = min({f(a) - p, f(b) - p, f(c) - p});

        cout << res << "\n";
    }

    return 0;
}