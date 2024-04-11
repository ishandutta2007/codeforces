#include <iostream>

using namespace std;

int main()
{
    long long res = 1, div = 1, n;
    cin >> n;
    n--;
    for (int i = 2; i <= 2 * n; ++i)
        res *= i;
    for (int i = 2; i <= n; ++i)
        div *= i;
    cout << res / div / div;
    return 0;
}