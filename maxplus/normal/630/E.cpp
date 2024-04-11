#include <iostream>

using namespace std;

int main()
{
    int64_t xl, xr, yb, yt, x, y;
    cin >> xl >> yb >> xr >> yt;
    x = xr - xl + 1, y = yt - yb + 1;
    cout << x * (y / 2) + (x + 1) / 2 * (y & 1);
    return 0;
}