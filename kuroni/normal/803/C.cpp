#include <iostream>
#include <math.h>
using namespace std;

long long n, ans = 0, k, lim;

int main()
{
    cin >> n >> k;
    if (k >= 141423)
    {
        cout << -1;
        return 0;
    }
    lim = k * (k + 1) / 2;
    for (long long i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            if (i >= lim)
                ans = max(ans, n / i);
            if (n / i >= lim)
                ans = max(ans, i);
        }
    if (ans == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < k; i++)
    {
        cout << i * ans << " ";
        n -= i * ans;
    }
    cout << n;
}