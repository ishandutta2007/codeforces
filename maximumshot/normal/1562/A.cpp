#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        // a mod b
        // l <= a <= b <= r
        // b -> fix
        // a = 2 * b - 1 <= r
        // l <= b <= (r + 1) / 2
        int sep = (r + 1) / 2;
        int res = 0;
        if (l <= sep) res = max(0, sep - 1);
        sep = max(sep, l);
        res = max(res, r % sep);
        if (l <= sep && sep < r) res = max(res, r % (sep + 1));
        cout << res << "\n";
    }

    return 0;
}