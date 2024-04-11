#include <algorithm>
#include <iostream>

using namespace std;

long long a[1000000];

int main()
{
    long long n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (long long i = n - 1; i > -1; --i)
        ans += a[i] * min(i + 2, n);
    cout << ans;
    return 0;
}