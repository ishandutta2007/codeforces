#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = INT_MAX;

    for (int i = 1 ; i + 2 <= n ; ++ i) {
        ans = min(ans, a[i + 2] - a[i]);
    }
    cout << max(0, ans) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}