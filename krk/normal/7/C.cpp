#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, c;

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll xx, yy;
    ll g = gcd(b, a % b, xx, yy);
    x = yy; y = xx - a / b * yy;
    return g;
}

int main()
{
    ll g, x, y;
    cin >> a >> b >> c;
    g = gcd(a, b, x, y);
    if (c % g == 0) cout << -x * (c / g) << " " << -y * (c / g) << endl;
    else cout << "-1\n";
    return 0;
}