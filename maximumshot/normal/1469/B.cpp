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
        int res = 0;
        for (int i = 0; i < 2; i++) {
            int n;
            cin >> n;
            int mx = 0;
            for (int s = 0, x, j = 0; j < n; j++) {
                cin >> x;
                s += x;
                mx = max(mx, s);
            }
            res += mx;
        }
        cout << res << "\n";
    };

    return 0;
}