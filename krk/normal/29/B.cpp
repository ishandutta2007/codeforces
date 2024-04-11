#include <iostream>
#include <iomanip>
using namespace std;

int l, d, v, g, r;

int main()
{
    cin >> l >> d >> v >> g >> r;
    double tim = (double) d / v;
    double tmp = tim - (g + r) * int(tim / (g + r));
    if (tmp >= g) tim += r + g - tmp;
    tim += (double) (l - d) / v;
    cout << fixed << setprecision(8) << tim << endl;
    return 0;
}