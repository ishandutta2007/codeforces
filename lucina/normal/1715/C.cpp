#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, nq;
int64_t a[nax];

void solve() {
    cin >> n >> nq;

    int64_t sum = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 2 ; i <= n ; ++ i) {
        sum += 1ll * (a[i] != a[i - 1]) * (i - 1) * (n - i + 1);
    }

    sum += 1ll * n * (n + 1) / 2;

    for (int i = 1 ; i <= nq ; ++ i) {
        int p, x;
        cin >> p >> x;
        if (p > 1) sum -= 1ll * (a[p] != a[p - 1]) * (p - 1) * (n - p + 1);
        if (p < n) sum -= 1ll * (a[p] != a[p + 1]) * (p) * (n - p);

        a[p] = x;

        if (p > 1) sum += 1ll * (a[p] != a[p - 1]) * (p - 1) * (n - p + 1);
        if (p < n) sum += 1ll * (a[p] != a[p + 1]) * (p) * (n - p);

        cout << sum << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }
}