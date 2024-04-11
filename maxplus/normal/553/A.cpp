#include <iostream>

using namespace std;

int C[1005][1005];
const int mod = 1000000007;

int c(int n, int k)
{
    if (n < 2 * k)
        k = n - k;
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    if (C[n][k] != 0)
        return C[n][k];
    C[n][k] = c(n - 1, k - 1) + c(n - 1, k);
    if (C[n][k] < mod)
        return C[n][k];
    else
        return C[n][k] -= mod;
}

int main()
{
    int n, am, c;
    int64_t ans = 1;
    cin >> n;
    cin >> am;
    for (int i = 1; i < n; ++i)
    {
        cin >> c;
        ans = (ans * ::c(am + c - 1, c - 1)) % mod;
        am += c;
    }
    cout << ans;
    return 0;
}