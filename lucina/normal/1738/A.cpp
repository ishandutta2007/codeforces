#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
array <int, 2> a[nax];

void solve() {
    cin >> n;
    int c[2]{};
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i][1];
        c[a[i][1]] += 1;
    }
    int64_t ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i][0];
        ans += a[i][0];
    }
    int y = min(c[0], c[1]);
    if (c[0] == c[1]) ans -= (*min_element(a + 1, a + 1 + n))[0];
    c[0] = c[1] = y;
    sort(a + 1, a + 1 + n, greater<>());

    for (int i = 1 ; i <= n ; ++ i) {
        if (c[a[i][1]] > 0) {
            ans += a[i][0];
            c[a[i][1]] -= 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}