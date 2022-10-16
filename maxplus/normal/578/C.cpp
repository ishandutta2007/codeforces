#include <iostream>
#include <numeric>

using namespace std;

typedef long double ld;

ld maxs(ld* b, int l)
{
    ld ans = b[0], sum = 0;
    for (int i = 0; i < l; ++i)
        ans = max(ans, sum = max(sum, 0.L) + b[i]);
    return ans;
}

ld mins(ld* b, int l)
{
    ld ans = b[0], sum = 0;
    for (int i = 0; i < l; ++i)
        ans = min(ans, sum = min(sum, 0.L) + b[i]);
    return ans;
}

ld a[200001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long double l = -10000, r = 10000, b, s;
    for (int i = 0; i < 100; ++i)
    {
        ld m = (l + r) / 2;
        for (int i = 0; i < n; ++i)
            a[i] -= m;
        b = maxs(a, n);
        s = mins(a, n);
        for (int i = 0; i < n; ++i)
            a[i] += m;
        if (b > -s)
            l = m;
        else
            r = m;
    }
    cout.precision(20);
    cout << fixed;
    cout << b;
    return 0;
}