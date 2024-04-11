#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T  ; T -- ; ) {
        int a, b, c, d, xx, yy, x[2], y[2];
        cin >> a >> b >> c >> d;
        cin >> xx >> yy >> x[0] >> y[0] >> x[1] >> y[1];
        auto test = [&] () -> bool{

        int dx = xx - a + b, dy = yy - c + d;
        if (!(dx >= x[0] && dx <= x[1] && dy <= y[1] && dy >= y[0])) return false;

        int lenx = max(xx - x[0], x[1] - xx);
        int leny = max(yy - y[0], y[1] - yy);

        if (a + b > 0)
            if (lenx == 0) return false;
        if (c + d > 0)
            if (leny == 0) return false;

        return true;

        };

        if (test()) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
    Good Luck
        -Lucina
*/