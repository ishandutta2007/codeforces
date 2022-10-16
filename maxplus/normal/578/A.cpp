#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    long double a, b, x;
    cin >> a >> b;
    x = b;
    cout.precision(20);
    cerr.precision(20);
    cout << fixed;
    cerr << fixed;
    if (a < b)
        (cout << -1), exit(0);
    while (1)
    {
        int st = a / x;
        cerr << "st " << st << '\n';
        if ((st & 1) == 0)
        {
            if (b - (a - st * x) < 1e-10)
                break;
            cerr << "d " << b - (a - st * x) << '\n';
            x = (b - (a - st * x)) / (st + 1) + x;
        }
        else
        {
            if (b - x + (a - st * x) < 1e-10)
                break;
            cerr << "d " << b - x + (a - st * x) << '\n';
            x = (b - x + (a - st * x)) / (st + 1) + x;
        }
    }
    cout << x;
    return 0;
}