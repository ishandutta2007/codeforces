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
        int n, m;
        cin >> n >> m;
        int mn_neg = inf;
        int mn_pos = inf;
        int res = 0;
        int cnt = 0;
        int cz = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (x > 0) {
                    res += x;
                    mn_pos = min(mn_pos, x);
                } else if (x < 0) {
                    res -= x;
                    cnt++;
                    mn_neg = min(mn_neg, -x);
                } else {
                    cz++;
                }
            }
        }
        if (cnt % 2 && cz == 0) {
            if (n * m - cnt - cz == 0)
                res -= 2 * mn_neg;
            else {
                res -= mn_neg + mn_pos;
                res = max(res + mn_pos - mn_neg, res + mn_neg - mn_pos);
            }
        }
        cout << res << "\n";
    }

    return 0;
}