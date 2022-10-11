#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    auto query = [&](int w) {
        cout << "? " << w << endl;
        int res;
        cin >> res;
        return res;
    };

    int l = 0, r = n * 2000 + (n - 1);
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (query(mid) == 1 ? r : l) = mid;
    }

    int value = r, ans = value;
    for (int i = 2; i <= n; i++) {
        int cur = query(value / i);
        if (cur) ans = min(ans, cur * (value / i));
    }
    cout << "! " << ans << endl;
}