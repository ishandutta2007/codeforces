#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int ans = 0;
    const int INF = 1e9;
    for (int i = 2 ; i < n ; ++ i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            a[i + 1] = max(a[i], i + 2 <= n ? a[i + 2] : 0), ans += 1;
    }
    cout << ans << '\n';
    for (int i = 1 ; i <= n ; ++ i)
        cout << a[i] << ' ';
    cout << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    GL
*/