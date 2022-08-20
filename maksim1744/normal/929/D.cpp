#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mx = 100001;

typedef long long ll;

main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> g(n - 1), k(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    if (a > b) {
        a = n - a + 1;
        b = n - b + 1;
        reverse(g.begin(), g.end());
        reverse(k.begin(), k.end());
    }
    a--;
    b--;
    vector<bool> hv(mx, false);
    int i1 = a;
    vector<int> bk(n);
    for (int i = 0; i < n; i++) {
        bk[i] = i;
    }
    vector<int> nx(n);
    for (int i = 0; i < n; i++) {
        nx[i] = i;
    }
    for (int i = a; i <= b; i++) {
        hv[k[i]] = true;
        while (i1 > 0 && hv[g[i1 - 1]]) {
            i1--;
            hv[k[i1]] = true;
        }
        bk[i] = i1;
    }
    hv.assign(mx, false);
    i1 = a;
    for (int i = a; i >= 0; i--) {
        hv[k[i]] = true;
        while (i1 < n - 1 && hv[g[i1]]) {
            i1++;
            hv[k[i1]] = true;
        }
        nx[i] = i1;
    }
    ll x, y;
    y = b;
    int l, r;
    l = -1;
    r = a + 1;
    int c;
    while (r - l > 1) {
        c = (r + l) / 2;
        if (nx[c] < b) {
            r = c;
        }
        else {
            l = c;
        }
    }
    if (l == -1) {
        cout << -1;
        return 0;
    }
    x = l;
    ll ans = y - x;
    ll x0 = -1, y0 = -1;
    while (x != a || y != a) {
        x0 = x;
        y0 = y;
        l = a - 1;
        r = b + 1;
        while (r - l > 1) {
            c = (r + l) / 2;
            if (bk[c] > x) {
                l = c;
            }
            else {
                r = c;
            }
        }
        if (r == b + 1) {
            cout << -1;
            return 0;
        }
        y = r;
        ans += y - x;
        l = -1;
        r = a + 1;
        while (r - l > 1) {
            c = (r + l) / 2;
            if (nx[c] < y) {
                r = c;
            }
            else {
                l = c;
            }
        }
        if (l == -1) {
            cout << -1;
            return 0;
        }
        x = l;
        ans += y - x;
        if (x == x0 && y == y0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}