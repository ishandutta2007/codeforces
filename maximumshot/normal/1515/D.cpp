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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> cl(n + 1), cr(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i < l)
                cl[x]++;
            else
                cr[x]++;
        }
        for (int x = 1; x <= n; x++) {
            int mn = min(cl[x], cr[x]);
            cl[x] -= mn;
            cr[x] -= mn;
            l -= mn;
            r -= mn;
        }
        int res = 0;
        if (l > r)
            swap(l, r), swap(cl, cr);
        for (int x = 1; x <= n; x++) {
            if (cr[x] > 1) {
                int tmp = min(cr[x], r - l);
                if (tmp % 2)
                    tmp--;
                r -= tmp;
                res += tmp / 2;
                cr[x] -= tmp;
            }
        }
        if (l < r) {
            res += l;
            r -= l;
            res += r;
        } else {
            res += r;
        }
        cout << res << "\n";
    }

    return 0;
}