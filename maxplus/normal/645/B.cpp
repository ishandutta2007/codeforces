#include <iostream>

using namespace std;

int main()
{
    int64_t n, k, ans = 0;
    cin >> n >> k; k = min(k, n / 2);
    for (int i = 0; i < k; ++i)
        ans += n - 2 * i - 1 + n - 2 * i - 2;
    cout << ans;
    return 0;
}