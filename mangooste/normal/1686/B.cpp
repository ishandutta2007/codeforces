#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto &x : p) cin >> x;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] > p[i + 1]) {
                ans++;
                i++;
            }
        }
        cout << ans << '\n';
    }
}