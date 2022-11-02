#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <ios>

using namespace std;

const int maxn = 200100;

int n, a, b, c, t[maxn];

bool check(int na, int nb, int nc, int k) {
    if (na > k) nb += na - k;
    if (nb > k) nc += nb - k;
    return nc <= k;
}

int calc(int na, int nb, int nc, int mab, int mabc) {
    int k = min(mab, nb);
    nb -= k, mab -= k;
    k = min(mab, na);
    na -= k;
    k = min(mabc, nc);
    nc -= k, mabc -= k;
    k = min(mabc, nb);
    nb -= k, mabc -= k;
    k = min(mabc, na);
    na -= k, mabc -= k;

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(na, nb, nc, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n);

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    assert(a <= b && b <= c);

    int na = 0, nb = 0, nc = 0, nab = 0, nac = 0, nbc = 0, ans = 0;
    int mab = 0, mabc = 0;
    if (c <= a + b) {
        for (int i = 0; i < n; i++) {
            if (t[i] <= a) na++;
            else if (t[i] <= b) nb++;
            else if (t[i] <= c) nc++;
            else if (t[i] <= a + b) nab++;
            else if (t[i] <= a + c) nac++;
            else if (t[i] <= b + c) nbc++;
            else if (t[i] <= a + b + c) ans++;
            else {
                cout << "-1\n";
                return 0;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (t[i] <= a) na++;
            else if (t[i] <= b) nb++;
            else if (t[i] <= a + b) nab++;
            else if (t[i] <= c) nc++;
            else if (t[i] <= a + c) nac++;
            else if (t[i] <= b + c) nbc++;
            else if (t[i] <= a + b + c) ans++;
            else {
                cout << "-1\n";
                return 0;
            }
        }
    }

    //cout << na << ' ' << nb << ' ' << nc << ' ' << nab << ' ' << nac << ' ' << nbc << ' ' << ans << endl;

    ans += nbc;
    na -= min(na, nbc);
    ans += nac;
    mab = nac;

    if (c <= a + b) {
        int best = 1e9;
        for (int i = 0; i <= nc; i++) { //how many of nc go to nab
            mabc = nab + i;
            best = min(best, mabc + calc(na, nb, nc - i, mab, mabc));
        }
        ans += best;
    } else {
        int best = 1e9;
        for (int i = 0; i <= nab; i++) { //how many of nab go to nc
            mabc = nab - i;
            best = min(best, mabc + calc(na, nb, nc + i, mab, mabc));
        }
        ans += best;
    }

    cout << ans << '\n';
}