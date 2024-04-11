#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        int n, k;
        cin >> n >> k;
        /**

        1 1 1 1 { 1 1 1 1}
        {  k   }   k
        */

        int ans;

        if (k < n) {
            ans = (n % k == 0 ? 1 : 2);
        } else {
            ans = (k + n - 1) / n;
        }

        cout << ans << '\n';
    }
}