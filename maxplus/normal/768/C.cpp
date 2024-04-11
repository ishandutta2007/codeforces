#include <iostream>
#include <cstring>

using namespace std;

int _a[1024], _b[1024], *a = _a, *b = _b;

int main()
{
    int n = 100000, k = 100000, x = 569, t;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i)
        cin >> t, a[t]++;
//        t = i % 1024, a[t] += 1;
    while (k--)
    {
        memset(b, 0, sizeof(*b) * 1024);
        for (int i = 0, e = 0; i < 1024; ++i)
            b[i] += (a[i] + e) / 2,
            b[i ^ x] += (a[i] + (e ^ 1)) / 2, e ^= a[i] & 1;
        swap(a, b);
    }
    for (int i = 1023; ~i; --i)
        if (a[i])
            cout << i << ' ', i = 0;
    for (int i = 0; i < 1024; ++i)
        if (a[i])
            cout << i << ' ', i = 1024;
    return 0;
}