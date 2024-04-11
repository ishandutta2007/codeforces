#include <iostream>

using namespace std;

int64_t a[100000];

int main()
{
    int64_t n, ans = -1e18;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
        a[i] = max(a[i] - a[i + 1], a[i + 1] - a[i]);
    for (int i = 0; i < n - 1; ++i)
        a[i] = (i? a[i - 1]: 0) + a[i] * (1 - 2 * (i & 1));
    for (int64_t i = 0, cmin = 0; i < n - 1; ++++i)
        cmin = i? min(cmin, a[i - 1]): cmin,
        ans = max(ans, a[i] - cmin);
    for (int64_t i = 1, cmax = 0; i < n - 1; ++++i)
        cmax = i? max(cmax, a[i - 1]): cmax,
        ans = max(ans, -(a[i] - cmax));
    cout << ans;
    return 0;
}