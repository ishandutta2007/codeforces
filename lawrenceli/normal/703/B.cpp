#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, c[100100];
bool u[100100];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        u[a - 1] = 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (!u[i] && !u[j]) ans += c[i] * c[j];

        if (u[i]) {
            ans += ll(c[i]) * (sum - c[i]);
        }
    }

    ll tot = 0;
    for (int i = 0; i < n; i++)
        if (u[i])
            tot += c[i];

    tot *= tot;
    for (int i = 0; i < n; i++)
        if (u[i])
            tot -= c[i] * c[i];
    ans -= tot / 2;
    cout << ans << '\n';
}