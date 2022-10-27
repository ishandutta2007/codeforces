#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


void solve () {
    int m, d, w; /// month day week
    cin >> m >> d >> w;
    int shift = d % w;
    int ok;

    /**
       6 7 4
    */

    if (shift == 1) {
        ok = 1;
    } else {
        ok = w / gcd(w, (shift - 1 + w) % w);
    }

    int ac = min(d, m) - 1;
    int latest = (ac / ok);

    long long ans = 0;
    ans += 1LL * latest * (min(d, m));
    ans -= (1LL * latest * (latest + 1) / 2) * ok;

    cout << ans << '\n';



}
    /// x < y <= min(d, m)


int main () {
    cin.tie(0)->sync_with_stdio(false);


    int T;
    for (cin >> T ;  T-- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/