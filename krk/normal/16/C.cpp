#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, x, y;

ll gcd(ll x, ll y)
{
    if (!x) return y;
    else return gcd(y % x, x);
}

int main()
{
    cin >> a >> b >> x >> y;
    ll d = gcd(x, y); x /= d; y /= d;
    ll k = a / x;
    if (k * y <= b) cout << k * x << " " << k * y << endl;
    else {
         k = b / y;
         if (k * x <= a) cout << k * x << " " << k * y << endl;
         else cout << "0 0\n";
    }
    return 0;
}