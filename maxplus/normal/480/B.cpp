#include <algorithm>
#include <iostream>
#define N 100000

using namespace std;

int64_t l, n, x, y, a[N];
bool f(int64_t x)
{
    for (l = 0; l < n; ++l)
        if (binary_search(a + l, a + n, a[l] + x))
            return 1;
    return 0;
}

bool _f(int64_t x)
{
    for (l = n - 1; l > 0; --l)
        if (binary_search(a, a + l, a[l] - x))
            return 1;
    return 0;
}

int main()
{
    bool f1 = 0, f2 = 0, f3 = 0;
    cin >> n >> l >> x >> y;
    for (int64_t i = 0; i < n; ++i)
        cin >> a[i];
    if (f(x))
        f1 = 1;
    if (f(y))
        f2 = 1;
    if (f(x + y))
        f3 = 1;
    if (f1 && f2)
    {
        cout << 0;
        return 0;
    }
    if (f1)
    {
        cout << "1\n" << y;
        return 0;
    }
    if (f2)
    {
        cout << "1\n" << x;
        return 0;
    }
    if (f3)
    {
        cout << "1\n" << a[l] + x;
        return 0;
    }
    if (f(y - x))
    {
        if (a[l] + y < a[n - 1])
        {
            cout << "1\n" << a[l] + y;
            return 0;
        }
    }
    if (_f(y - x))
    {
        if (a[l] - y > 0)
        {
            cout << "1\n" << a[l] - y;
            return 0;
        }
    }
//    if (x == y)
//    {
//        cout << "1\n" << x;
//        return 0;
//    }
    cout << "2\n" << x << ' ' << y;
    return 0;
}