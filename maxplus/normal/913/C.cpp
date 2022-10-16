#include <iostream>

using namespace std;

constexpr int N = 30;

int64_t a[N], n, x;

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i)
            a[i] = min(a[i], 2 * a[i - 1]);
    }
    int64_t res = ((x + (1 << (n - 1)) - 1) >> (n - 1)) * a[n - 1], cp = (x >> (n - 1)) * a[n - 1];
    for (int i = n - 2; i > -1; --i)
        if (x & (1 << i))
            cp += a[i];
        else
            res = min(res, cp + a[i]);
    res = min(res, cp);
    cout << res;
    return 0;
}