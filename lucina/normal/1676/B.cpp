#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;

/**
    Imagine array v_i - i
    The operation took place like
    0 -1 -2 -3 0 -1 -2 -3
    each zeros will be moved to next zero
    -1 -2 -3 0 -1 -2 -3 0
    and add 1 to everything
    0 -1 -2 0 0 -1 -2
    Well, it just shifting array to the left k times
*/
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    cout << accumulate(a + 1, a + 1 + n, 0) - n * (*min_element(a + 1, a + 1 + n)) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}