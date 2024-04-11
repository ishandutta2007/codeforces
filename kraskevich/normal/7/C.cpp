#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b, ll & x, ll & y) {
     if(!a) {
            x = 0, y = 1;
            return b;
     }
     ll x1, y1;
     ll g = gcd(b % a, a, x1, y1);
     x = y1 - (b / a) * x1;
     y = x1;
     return g;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y, g;
    g = gcd(a, b, x, y);
    if(c % g)
         cout << -1;
    else
        cout << -(c / g) * x << " " << -(c / g) * y << endl;
    cin >> a;
    return 0;
}