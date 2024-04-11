#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long;
const ll INF = 1e18;

ll f[22];
ll pw[22];

void solve() {
    ll a;
    int s;
    cin >> a >> s;

    ll n = a;
    int t = 0;
    ll p = 1;
    while (a > 0) {
        f[t ++] = a % 10;
        a /= 10;
    }
    pw[t - 1] = 1;
    for (int j = t - 2 ; j >= 0 ; -- j)
        pw[j] = pw[j + 1] * 10;

    reverse(f, f + t);

    int cur_sum = 0;
    if (accumulate(f, f + t, 0) <= s) {
        cout << 0 << '\n';
        return ;
    }

    ll tot = 0;
    ll ans = 3 * INF;
    for (int i = 0 ; i < t ; ++ i) {
        for (int d = f[i] + 1 ; d <= min(9, pw[i] == INF ? 2 : 9) ; ++ d) {
            ll now = tot + pw[i] * d;
            int res = s - cur_sum - d;
            if (res < 0) continue;
            ans = min(ans, now);
        }
        cur_sum += f[i];
        tot += pw[i] * f[i];
    }


    if (ans == 3 * INF) {
        ans = pw[0] * 10;
    }


    cout << ans - n << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    I have been too lazy, lately.
*/