#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300005;

int n, a[N];
long long su = 0, ans = 0, msk[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> msk[i];
        su += a[i];
    }
    if (su < 0)
    {
        for (int i = 1; i <= n; i++)
            a[i] = -a[i];
        su = -su;
    }
    for (int b = 0; b < 62; b++)
    {
        long long cur = 0;
        for (int i = 1; i <= n; i++)
            if (msk[i] == (1LL << b))
                cur += a[i];
        if (cur > 0)
            ans ^= (1LL << b);
        for (int i = 1; i <= n; i++)
            if (msk[i] >> b & 1)
            {
                msk[i] ^= (1LL << b);
                if (cur > 0)
                    a[i] = -a[i];
            }
    }
    cout << ans;
}