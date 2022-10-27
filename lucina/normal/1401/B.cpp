#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        int a, b, c;
        int x, y, z;
        cin >> a >> b >> c;
        cin >> x >> y >> z; /// 0, 1, 2
        int ans = 0;

            int s = min(c, y);
            ans += 2 * s;
            c -= s;
            y -= s;
        s = min(a, z);
        a -= s;
        z -= s;

        s = min(c, z);
        c -= s;
        z -= s;
        ans -= 2 * z;
        cout << ans << '\n';
    }
}