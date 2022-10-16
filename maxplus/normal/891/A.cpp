#include <algorithm>
#include <iostream>

using namespace std;

inline int my_gcd(int a, int b) {
    if (__builtin_expect(a % b == 0, 1))
        return b;
    return my_gcd(b, a % b);
}

int main()
{
    int n, a[2000], res = 1e4, to = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], to += a[i] > 1;
    if (to < n)
        return cout << to << '\n', 0;
    for (int i = 0; i < n; ++i)
        for (int l = 1, g = a[i]; i + l <= n && l < res; ++l)
            if (__builtin_expect((g = my_gcd(a[i + l - 1], g)) == 1, 0)) {
                res = min(res, l);
                break;
            }
    cout << (res <= n? res + n - 2: -1) << '\n';
    return 0;
}