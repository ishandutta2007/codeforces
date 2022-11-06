#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long a, b;
    unsigned long long x, y;
    cin >> a >> b;
    x = a - b;
    x /= 2;
    unsigned long long p = a - x;
    //cout << x << ' ' << p << x && p;

    if (a < b || (x & p) != x)
    {
        cout << -1;
        return 0;
    }
    y = x + b;
    if (a %2 != b % 2)
    {
        cout << -1;
        return 0;
    }
    cout << x << ' ' << y;
    return 0;
}