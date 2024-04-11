#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int n = (1<<20);
const int mod = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        assert(a < b);
        assert(b < c);
        int y = b;
        int x = a + y * (int)(1e9);
        int z = c + x;
        assert(x % y == a);
        assert(y % z == b);
        assert(z % x == c);
        cout << x << " " << y << " " << z << endl;
    }
}