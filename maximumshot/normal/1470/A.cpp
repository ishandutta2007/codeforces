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
        vector<int> k(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> k[i];
        vector<int> c(m + 1);
        for (int i = 1; i <= m; i++)
            cin >> c[i];
        sort(k.begin() + 1, k.end());
        int bl = 0, br = min(n, m) + 1, bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            int ok = 1;
            for (int j = 1; j <= bm; j++) {
                if (j > k[n - bm + j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                bl = bm;
            else
                br = bm;
        }
        ll S = 0;
        for (int i = 1; i <= n; i++)
            S += c[k[i]];
        ll res = S;
        ll pr = 0;
        for (int j = 1; j <= bl; j++) {
            pr += c[j];
            S -= c[k[n - j + 1]];
            res = min(res, pr + S);
        }
        cout << res << "\n";
    }

    return 0;
}