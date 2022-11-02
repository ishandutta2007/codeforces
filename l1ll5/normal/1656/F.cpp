#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 200000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        LL s = 0;
        vector<LL> a(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            s += a[i];
        }
        vector<LL> sum(n);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i += 1) {
            if (i) sum[i] = sum[i - 1];
            sum[i] += a[i];
        }
        if (s + (n - 2) * a[0] > 0) {
            cout << "INF\n";
            continue;
        }
        if (s + (n - 2) * a.back() < 0) {
            cout << "INF\n";
            continue;
        }
        LL ans = LLONG_MIN;
        LL L = a[0], R = a.back();
        for (int i = 0; i < n; i += 1) {
            LL ret = 0, t = -a[i];
            if (i) ret += 1ll * (sum[i - 1] + i * t) * (R + t);
            LL p = 1ll * (n - i - 1) * t;
            ret += 1ll * (sum.back() - sum[i] + p) * (L + t);
            ret -= 1ll * (n - 1) * t * t + (L + t) * (R + t);
            ans = max(ans, ret);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
-3 -2 -1 0 1 2 3

*/

/*
sum + (n-2) * min
sum + (n-2) * max
*/