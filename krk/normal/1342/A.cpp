#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x, y;
ll a, b;

int main()
{
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cin >> a >> b;
        ll res = ll(abs(x - y)) * a;
        b = min(b, 2 * a);
        if (min(x, y) > 0) res += ll(b) * min(x, y);
        else if (max(x, y) < 0) res += ll(b) * (-max(x, y));
        cout << res << endl;
    }
    return 0;
}