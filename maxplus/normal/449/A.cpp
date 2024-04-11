#include <iostream>

using namespace std;

int main()
{
    long long a, b, ans = 0, k;
    cin >> a >> b >> k;
    if (a < b)
        swap(a, b);
    if (a + b - 2 < k)
    {
        cout << -1;
        return 0;
    }
    if (k >= a - 1)
        ans = b / (k - a + 2);
    ans = max(ans, max((b / (k + 1)) * a, (a / (k + 1)) * b));
    if (k >= b - 1)
        ans = max(ans, a / (k - b + 2));
    if (ans > 0)
        cout << ans;
    else
        cout << -1;
    return 0;
}