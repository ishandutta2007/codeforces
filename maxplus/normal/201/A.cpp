#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, x;
    cin >> x;
    if (x == 3)
    {
        cout << 5;
        return 0;
    }
    n = 1;
    while ((n * n + 1) / 2 < x)
        n += 2;
    cout << n;
    return 0;
}