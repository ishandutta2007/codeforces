
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, m, sx, sy, ex, ey;
int q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    ll d = __gcd(n, m);
    while(q--) {
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;
        sy /= (sx == 1 ? n : m) / d;
        ey /= (ex == 1 ? n : m) / d;
        cout << (sy == ey ? "YES" : "NO") << endl;
    }
}