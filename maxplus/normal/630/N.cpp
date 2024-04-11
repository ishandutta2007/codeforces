#include <iostream>

using namespace std;

int main()
{
    long double a, b, c;
    cin >> a >> b >> c;
    if (a < 0)
        a = -a, b = -b, c = -c;
    cout << fixed, cout.precision(30);
    cout << (-b + __builtin_sqrtl(b * b - 4 * a * c)) / 2 / a << '\n';
    cout << (-b - __builtin_sqrtl(b * b - 4 * a * c)) / 2 / a;
    return 0;
}