#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ll r,x,y,a,b;
    cin >> r >> x >> y >> a >> b;
    x -= a;
    y -= b;
    if (x == 0 && y == 0) { cout << 0 << endl; return 0; }

    x *= x;
    y *= y;
    r *= 2;
    r *= r;
    ll k = (x+y+r-1)/r;
    ll f = sqrt(k);
    while (f*f > k) --f;
    while (f*f < k) ++f;
    cout << f << endl;
}