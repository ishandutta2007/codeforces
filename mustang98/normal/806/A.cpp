#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll pop(ll x, ll y, ll p, ll q) {
    ll needc = p - x;
    ll needz = q - y;
    if (needc < 0 || needz < 0) return -1;
    if (needc > needz) return -1;
    return needz;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    ll x, y, p, q;
    cin >> T;
    while (T--) {
        cin >> x >> y >> p >> q;
       // ll g = gcd(x, y);
       // x /= g;
       // y /= g;
        if (p == 0 && x > 0 || p == q && x < y) {
            cout << -1 << "\n";
            continue;
        }
        ll ch1 = x * q, ch2 = p * y;
        if (ch1 == ch2) {
            cout << 0 << "\n";
            continue;
        }
        ll l = 1, r = 2000000000;
        if (pop(x, y, p, q) != -1) {
            cout << pop(x, y, p, q) << "\n";
            continue;
        }
        if (pop(x, y, p * r, q * r) == -1) {
            cout << -1 << "\n";
            continue;
        }
        while (l + 1 < r) {
            ll mid = (r - l) / 2 + l;
            if (pop(x, y, p * mid, q * mid) == -1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << pop(x, y, p * r, q * r) << "\n";
    }
    return 0;
}