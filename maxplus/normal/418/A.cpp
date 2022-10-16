#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (2 * k + 1 > n)
    {
        cout << -1;
        return 0;
    }
    cout << n * k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            cout << '\n' << i << ' ' << (i + j - 1) % n + 1;
    return 0;
}