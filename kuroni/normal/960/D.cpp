#include <bits/stdc++.h>
using namespace std;

int q, t;
long long x, k, add[64];

long long transform(long long u)
{
    int bs = 63 - __builtin_clzll(u);
    long long md = 1LL << bs;
    u -= md;
    return (u + add[bs]) % md + md;
}

long long value(long long u)
{
    int bs = 63 - __builtin_clzll(u);
    long long md = 1LL << bs;
    u -= md;
    return (u - add[bs] + md) % md + md;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--)
    {
        cin >> t >> x;
        if (t <= 2)
        {
            int bs = 63 - __builtin_clzll(x);
            long long md = 1LL << bs;
            cin >> k;
            ((k %= md) += md) %= md;
            for (int i = bs; i <= (t == 1 ? bs : 60); i++)
            {
                (add[i] += k) %= md;
                k *= 2; md *= 2;
            }
        }
        else
        {
            long long ori = transform(x);
            while (ori != 0)
            {
                cout << value(ori) << " ";
                ori /= 2;
            }
            cout << '\n';
        }
    }
}