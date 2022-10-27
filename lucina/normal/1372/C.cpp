#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;

void solve () {
    cin >> n;

    int b = 0;
    int ans = 0;
    int from = 0;

    for (int i = 1 ; i <= n;  ++ i) {
        int x;
        cin >> x;
        if (x == i) {
            if (from != x - 1) {
                ++ ans;
            }
            from = x;
        }
    }

    if (from != n) ++ ans;

    ans = min(ans, 2);
    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;

    for (cin >> t ; t -- ; ) {
        solve();
    }
}
/*
    Firis is not airhead!
*/