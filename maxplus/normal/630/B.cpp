#include <iostream>

using namespace std;

int main()
{
    long double n, a = 0.000000011, a1000 = 1;
    int t;
    cin >> n >> t;
    for (int i = 0; i < 1000; ++i)
        a1000 *= 1 + a;
    a1000 -= 1;
    while (t > 1000)
        n += n * a1000, t -= 1000;
    while (t)
        n += n * a, t -= 1;
    cout << fixed;
    cout.precision(30);
    cout << n;
    return 0;
}