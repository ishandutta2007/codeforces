#include <algorithm>
#include <iostream>

using namespace std;

inline bool corr(int a)
{
    while ((a & 1) == 0)
        a >>= 1;
    while (a % 3 == 0)
        a /= 3;
    return a == 1;
}

int a[100001], n, d;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> a[i]), d = __gcd(d, a[i]);
    for (int i = 0; i < n; ++i)
        if (!corr(a[i] / d))
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}