#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double l, r, h, a, ans = 0, pi = 3.1415926535897932384626433832795;
    for (int i = 3; i <= 5; ++i)
    {
        cin >> l;
        a = (i - 2) * pi / i / 2;
        r = l / sin(pi - 2 * a) * sin(a);
        h = sqrtl(l * l - r * r);
//        cerr << h * r * r * sin(pi - 2 * a) * i / 6 << '\n';
        ans += h * r * r * sin(pi - 2 * a) * i / 6;
    }
    cout << fixed;
    cout.precision(30);
    cout << ans;
    return 0;
}