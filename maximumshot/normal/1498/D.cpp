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

const int D = 1e5;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> res(m + 1, -1);
    res[0] = 0;

    for (int i = 1; i <= n; i++) {
        int t;
        ll x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x = (x + D - 1) / D;
            for (int s = m; s >= 0; s--) {
                if (res[s] == -1)
                    continue;
                for (ll cn = 1; cn <= y && s + cn * x <= m && res[s + cn * x] == -1; cn++)
                    res[s + cn * x] = i;
            }
        } else {
            for (ll s = m; s >= 0; s--) {
                if (res[s] == -1)
                    continue;
                ll value = s;
                for (ll it = 0; it < y; it++) {
                     value = (value * x + D - 1) / D;
                     if (value > m || res[value] != -1)
                         break;
                     res[value] = i;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}