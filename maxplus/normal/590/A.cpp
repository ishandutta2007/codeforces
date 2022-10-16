#include <algorithm>
#include <iostream>

using namespace std;

int n, a[500001], l[500001], r[500001], ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        l[i] = (a[i] != a[i - 1])? l[i - 1] + 1: 0;
    for (int i = n - 2; i > -1; --i)
        r[i] = (a[i] != a[i + 1])? r[i + 1] + 1: 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, min(l[i], r[i])), a[i] ^= min(l[i], r[i]) & 1;
    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}