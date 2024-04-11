#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y;
        cin >> x >> y;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int lx = x + b - a;
        int ly = y + d - c;
        bool ok = (x1 <= lx && lx <= x2 && y1 <= ly && ly <= y2);
        if (a + b != 0)
            ok &= (x2 - x1) > 0;
        if (c + d != 0)
            ok &= (y2 - y1) > 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}