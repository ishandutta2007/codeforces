#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
int n;
int b[nax];
bool f[nax];
int out[nax];

void solve() {
    cin >> n;
    fill(f, f + 2 * n + 1, false);

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        f[b[i]] = true;
    }

    for (int i = 1, top = 0 ; i <= 2 * n ; ++ i) {
        if (!f[i]) out[++ top] = i;
    }

    int mn = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (b[i] < out[i]) ++ mn;
    }


    int l = 0, r = n - mn;
    int ans = 0;

    auto tst = [&](int x)->bool {
        int st = x + 1;
        int cur = 1;

        for (int i = st ; i <= n ; ++ i) {
            if (out[cur ++] > b[i]) return false;
        }
        for (int i = 1 ; i < st ; ++ i)
            if (out[cur ++] < b[i]) return false;
        return true;
    };

    //for (int i = 1 ; i <= n ; ++ i)
    //cout << i << " " << (tst(i) ? "OK" : "NOT") << '\n';

    while (l <= r) {
        int mid = l + r >> 1;
        if (tst(mn + mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    int rg = mn + ans;

    l = 0, r = mn, ans = 0;

    while (l <= r) {
        int mid = l + r >> 1;
        if (tst(mn - mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    int lf = mn - ans;
    cout << rg - lf + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}