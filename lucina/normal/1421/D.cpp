#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int64_t c[7];

void upd_min(int64_t &a, int64_t b) {
    a = min(a, b);
}

void solve() {
    int x, y;
    cin >> x >> y;

    for (int i = 1 ; i <= 6 ; ++ i) {
        cin >> c[i];
    }

    int64_t ans = numeric_limits<int64_t>::max();

    /**
        Is this O(1) festival round?
    */

    upd_min(ans,
            (x >= 0 ? c[6] * x : c[3] * -x)
            + (y >= 0 ? c[2] * y : c[5] * -y)
            );

            /**
            /\
            */
    upd_min(ans,
            (x >= 0 ? c[1] * x : c[4] * -x)
            + (y - x >= 0 ? c[2] * (y - x) : c[5] * (x - y))
            );

    upd_min(ans,
            (y >= 0 ? c[1] * y : c[4] * -y)
            + ((y - x) >= 0 ? c[3] * (y - x) : c[6] * (x - y))
            );


    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}