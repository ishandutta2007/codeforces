#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];
int64_t b[nax];
int64_t c[nax];

void solve() {

    cin >> n;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> c[i], -- c[i];
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (int i = 1 ; i <= n ; ++ i)
        cin >> b[i];

    int64_t longest = 0;
    int64_t ans = 0;


    for (int i = 2 ; i <= n ; ++ i) {
        /// first connect with a[i];
        /// b[i] -> c[i]

        if (a[i] == b[i]) {
            ans = max(ans, c[i] + 2);
            longest = c[i] + 2;
            continue;
        }
        int64_t new_longest = 0;
        new_longest = max(new_longest, c[i] + 2 + abs(b[i] - a[i]));

        ans = max(ans, c[i] + 2 + abs(b[i] - a[i]));

        if (i != 2) {
            int64_t f = longest - c[i - 1];
            ans = max(ans, c[i] + 2 + f + c[i - 1] - abs(b[i] - a[i]));
            new_longest = max(new_longest, c[i] + 2 + f + c[i - 1] - abs(b[i] - a[i]));
        }
        longest = new_longest;
       // cout << ans << '\n';
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}