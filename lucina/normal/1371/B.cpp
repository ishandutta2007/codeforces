#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        long long n, r;

        cin >> n >> r;

        long long ans = 0;

        /**
        from r = 1, ..., n - 1
        */

        long long w = min(n - 1, r);
        ans += w * (w + 1) / 2;
        if (r - w > 0) ++ ans;

        cout << ans << '\n';
    }
}
/*
    Song of leaving home.
*/