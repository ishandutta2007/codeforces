#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n;
ll a[nax], b[nax];

ll pref[nax];

void solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld %lld", a + i, b + i);
    }

    a[0] = a[n], b[0] = b[n];

    for (int i = 1 ; i <= n ; ++ i) {
        pref[i] = pref[i - 1] + max(0LL, a[i] - b[i - 1]);
    }

    ll ans = LLONG_MAX;

    for (int i = 1 ; i <= n ; ++ i) {
        ans = min(ans, a[i] + ( i < n ? pref[n] - pref[i] : 0) + pref[i - 1]);
    }

    printf("%lld\n", ans);
}

int main () {
    int T;

    for (cin >> T ;  T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/