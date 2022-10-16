#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1000000], ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int N = n;
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1])
        {
            a[i - 1] = 1e7;
            N--;
        }
    sort(a, a + n);
    n = N;
    for (int i = n - 2; i >= 0 && a[i] > ans; --i)
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] % a[i] > ans)
                ans = a[j] % a[i];
            j = max(j, upper_bound(a + j + 1, a + n, ((a[j]) / a[i]) * a[i] + ans) - a - 1);
        }
    cout << ans;
    return 0;
}