#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n, t, x[Maxn], y[Maxn], res;

ll Cross(ll a, ll b, ll xp, ll yp)
{
    ll x1 = x[b] - x[a], y1 = y[b] - y[a];
    ll x2 = xp - x[a], y2 = yp - y[a];
    return x1 * y2 - x2 * y1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll xp, yp;
        cin >> xp >> yp;
        res = 0;
        ll a, b = 2;
        for (a = 0; a < n; a++) {
            while (a != b && Cross(a, b, xp, yp) < 0) b = (b + 1) % n;
            if (a == b) break;
            if (a < b) res += (b - a - 2LL) * (b - a - 1LL) / 2LL;
            else res += (n - a + b - 2LL) * (n - a + b - 1LL) / 2LL;
                        if (a == b) { b = (b + 1) % n; continue; }
        }
        if (a < n) cout << "0\n";
        else cout << n * (n - 1LL) * (n - 2LL) / 6LL - res << endl;
    }
    return 0;
}