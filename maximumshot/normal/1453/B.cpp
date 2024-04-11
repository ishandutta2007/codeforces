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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll S = 0;
        for (int i = 1; i < n; i++)
            S += abs(a[i] - a[i - 1]);
        ll res = S;
        for (int i = 0; i < n; i++) {
            ll tmp = S;
            if (i > 0)
                tmp -= abs(a[i] - a[i - 1]);
            if (i + 1 < n)
                tmp -= abs(a[i] - a[i + 1]);
            if (0 < i && i + 1 < n)
                tmp += abs(a[i + 1] - a[i - 1]);
            res = min(res, tmp);
        }
        cout << res << "\n";
    }

    return 0;
}