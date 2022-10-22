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
        int n, u, v;
        cin >> n >> u >> v;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int res = inf * 2 + 10;
        int ok = 0;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i + 1]) > 1) {
                res = 0;
                ok = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i + 1]) == 1) {
                res = min(res, min(u, v));
                ok = 1;
            }
        }
        if (!ok) {
            res = min(res, min(2 * v, u + v));
        }
        cout << res << "\n";
    }

    return 0;
}