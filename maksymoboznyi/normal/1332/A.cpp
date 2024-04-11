#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int x, x1, x2, y, y1, y2, a, b, c, d;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (a + b != 0 && x1 == x2) {
            cout << "NO\n";
            continue;
        }

        if (c + d != 0 && y1 == y2) {
            cout << "NO\n";
            continue;
        }
        int p1 = min(a, b);
        a -= p1;
        b -= p1;
        p1 = min(c, d);
        c -= p1;
        d -= p1;
        //cout << a << ' ' << b <<' ' << c << ' ' << d << endl;
        if (x - x1 < a || x2 - x < b || y - y1 < c || y2 - y < d)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}