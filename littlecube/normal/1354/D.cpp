#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, bit[2000005];
signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n + q; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            for (; x <= 2 * n; x += x & -x)
                bit[x]++;
        }
        else
        {
            x = -x;
            int i = (1LL << (int)floor(log2(n))), r = 1;
            for (;;)
            {
                //cout << "e " << i << " " << bit[i] << " " << x << '\n';
                if (x <= bit[i])
                    r = i;
                if ((i & -i) == 1)
                    break;
                if (x > bit[i])
                    x -= bit[i], i += (i & -i) / 2;
                else if(x <= bit[i])
                    i -= (i & -i) / 2;
            }
            //cout << "E " << r << '\n';
            for (; r <= 2 * n; r += r & -r)
                bit[r]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (bit[i] > 0)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}