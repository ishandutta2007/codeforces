#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;

    int bar[35];
    memset(bar, 0, sizeof(bar));

    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        bar[__lg(x)] += 1;
    }
    int64_t ans = 0;

    for (int i = 0 ; i <= 31 ; ++ i)
        ans += 1LL * bar[i] * (bar[i] - 1);
    cout << ans / 2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T --  ;) {
        solve();
    }

}