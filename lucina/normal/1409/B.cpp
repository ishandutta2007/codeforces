#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int oa = a, ob = b, ox = x, oy = y, on = n;

        int can = min(n, a - x);
        n -= can;
        a -= can;
        can = min(n, b - y);
        b -= can;
        int64_t ans = LLONG_MAX;
        ans = min(ans, 1LL * a * b);

        a = ob, b = oa, x = oy, y = ox, n = on;
        can = min(n, a - x);
        n -= can;
        a -= can;
        can = min(n, b - y);
        b -= can;
        cout << min(ans, 1LL * a * b) << '\n';
    }
}
/*
    I have been too lazy, lately.
*/