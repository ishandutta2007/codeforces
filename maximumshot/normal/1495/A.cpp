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

    cout.precision(20);
    cout << fixed;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a, b;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0)
                a.push_back(y);
            else
                b.push_back(x);
        }
        sort(a.begin(), a.end(), [&](int x, int y) {
            return 1ll * x * x < 1ll * y * y;
        });
        sort(b.begin(), b.end(), [&](int x, int y) {
            return 1ll * x * x < 1ll * y * y;
        });
        ld res = 0;
        for (int i = 0; i < n; i++)
            res += sqrtl(max(ld(0), ld(a[i]) * ld(a[i]) + ld(b[i]) * ld(b[i])));
        cout << res << "\n";
    }

    return 0;
}