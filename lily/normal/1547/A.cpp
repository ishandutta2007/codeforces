#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        int ans = 0;
        if (xa == xb && xb == xc && min(ya, yb) < yc && yc < max(ya, yb))
            ans = 2;
        else if (ya == yb && yb == yc && min(xa, xb) < xc && xc < max(xa, xb))
            ans = 2;
        ans += abs(xa - xb) + abs(ya - yb);
        cout << ans << endl;
    }
}