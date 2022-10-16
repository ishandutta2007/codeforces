#include <iostream>
#include <algorithm>
//#include <cstdio>

using namespace std;

int main()
{
    int q = 350000;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> q;
//    freopen("out.txt", "r", stdin);
//    freopen("out", "w", stdout);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 2; i * i * i * i <= max(a, b); ++i)
        if (a % i == 0 || b % i == 0)
        {
            int x = 0, y = 0;
            while (a % i == 0)
                a /= i,
                ++x;
            while (b % i == 0)
                b /= i,
                ++y;
            if ((x + y) % 3 != 0)
                a = b = -1;
            else
            {
                int z = (x + y) / 3;
                int k = x - z, l = y - z;
                if (k < 0 || l < 0)
                    a = b = -1;
            }
        }
        if (a == -1)
        {
            cout << "no\n";
            continue;
        }
        int64_t x = a / __gcd(a, b);
        int64_t y = b / __gcd(a, b);
        if (x * x <= a && x * x * y == a &&
            y * y <= b && x * y * y == b)
        {
            cout << "yes\n";
            continue;
        }
        if (a == b)
        {
            int64_t x = __builtin_cbrtl(a);
            while (x * x * x > a)
                --x;
            while (x * x * x < a)
                ++x;
            if (x * x * x == a)
            {
                cout << "yes\n";
                continue;
            }
        }
        if (a < b)
            swap(a, b);
        x = __builtin_sqrtl(a);
        while (x * x > a)
            --x;
        while (x * x < a)
            ++x;
        if (x * x != a || x != b)
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}