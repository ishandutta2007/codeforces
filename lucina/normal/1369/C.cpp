#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
int a[nax];
int w[nax];

void solve () {
    cin >> n >> k;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (int i = 1 ; i <= k ; ++ i)
        cin >> w[i];

    sort(a + 1, a + 1 + n, greater<int>());
    sort(w + 1, w + 1 + k);

    long long ans = 0;

    for (int i = 1 ; i <= k ; ++ i) {
        ans += a[i];
        -- w[i];
    }

    int cur = k;

    for (int i = 1 ; i <= k ; ++ i) {
        ans += w[i] > 0 ? a[cur + w[i]] : a[i];
        cur += w[i];
    }

    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Leon is the best girl in A17.
*/