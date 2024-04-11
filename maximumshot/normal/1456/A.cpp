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
        int n, p, k;
        cin >> n >> p >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }

        int x, y;
        cin >> x >> y;

        ll res = inf64;

        vector<int> f(n);

        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n)
                f[i] = f[i + k];
            f[i] += !a[i];
        }

        for (int del = 0; n - del >= p; del++) {
            res = min(res, 1ll * del * y + 1ll * x * f[del + p - 1]);
        }

        cout << res << "\n";
    }

    return 0;
}