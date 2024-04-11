#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    ans = a[n - 1] - a[0];
    for (int i = 0 ; i < n ; ++ i) {
        ans = max(ans, a[i] - a[(i + 1) % n]);

    }
    for (int i = 1 ; i < n ; ++ i) {
        ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0 ; i + 1 < n ; ++ i)
        ans = max(ans, a[n - 1] - a[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    combined round~
    which faces?
    :D ? :E ? :O ? X<
*/