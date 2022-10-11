#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        ll b, x, y;
        cin >> n >> b >> x >> y;
        ll ans = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (last + x <= b) {
                last += x;
            } else {
                last -= y;
            }
            ans += last;
        }
        cout << ans << '\n';
    }
}