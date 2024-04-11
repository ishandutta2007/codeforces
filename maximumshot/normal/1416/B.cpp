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
        int n;
        cin >> n;
        ll S = 0;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S += a[i];
        }
        if (S % n) {
            cout << "-1\n";
            continue;
        }
        S /= n;
        vector<tuple<int, int, ll>> res;
        auto op = [&](int i, int j, ll x) {
            if (x == 0)
                return;
            a[i] -= x * i;
            a[j] += x * i;
            res.emplace_back(i, j, x);
        };
        int ok = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] % i) {
                if (i - a[i] > a[1]) {
                    ok = 0;
                    break;
                }
                op(1, i, i - a[i] % i);
            }
            op(i, 1, a[i] / i);
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        for (int i = 2; i <= n; i++) {
            op(1, i, S);
        }
        cout << (int) res.size() << "\n";
        for (auto [i, j, x] : res)
            cout << i << " " << j << " " << x << "\n";

    }

    return 0;
}