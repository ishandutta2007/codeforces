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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a.begin() + 1, a.end());

        auto calc = [&](int k) -> ll {
            ll res = 0;
            for (int j = n, i = 1; i <= n; i++) {
                // j < i
                // a[j] <= k - a[i]
                while (j > 0 && a[i] + a[j] > k) j--;
                res += min(i - 1, j);
            }
            return res;
        };

        cout << calc(r) - calc(l - 1) << "\n";
    }

    return 0;
}