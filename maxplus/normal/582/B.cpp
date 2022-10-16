#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n = 110, a[2 * (110 * 110 + 2 * 110 + (6 / 110 + 1) * 110)], ta[2 * (110 * 110 + 2 * 110 + (6 / 110 + 1) * 110)], am[301], ans, t;

int main()
{
    cin >> n >> t;
    int bound = 2 * (n * n + 2 * n + (6 / n + 1) * n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], am[a[i]]++;
    for (int i = 0; i < bound; ++i)
        a[i] = a[i % n];
    if (t <= 2 * bound / n)
    {
        memset(ta, 63, sizeof(ta));
        ta[0] = 0;
        for (int j = 0; j < t * n; ++j)
            *upper_bound(ta, ta + t * n + 2, a[j]) = a[j];
        cout << upper_bound(ta, ta + t * n + 2, 500) - ta - 1;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        memset(ta, 63, sizeof(ta));
        ta[0] = 0;
        for (int j = 0; j < bound; ++j) if (a[j] <= a[i])
            *upper_bound(ta, ta + bound + 2, a[j]) = a[j];
        int a1 = upper_bound(ta, ta + bound + 2, 500) - ta - 1;
        memset(ta, 63, sizeof(ta));
        ta[0] = 0;
        for (int j = 0; j < bound; ++j) if (a[j] >= a[i])
            *upper_bound(ta, ta + bound + 2, a[j]) = a[j];
        int a2 = upper_bound(ta, ta + bound + 2, 500) - ta - 1;
        ans = max(ans, a1 + a2 + (t - 2 * bound / n) * am[a[i]]);
    }
    cout << ans;
    return 0;
}