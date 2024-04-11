#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e5;
ll n, a[100000];
map<pair<ll,ll>, ll> m;
map<pair<ll,ll>, bool> u;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int l = 0; l < 9; l++)
        {
            ll x1 = 1;
            for (int j = 0; j < 9-l; j++)
                x1 *= 10;
            for (int r = l; r < 9; r++)
            {
                ll x2 = 1;
                for (int j = 0; j < 8-r; j++)
                    x2 *= 10;
                ll x3 = a[i] %x1 / x2;
             //   cout << l << ' ' << r << ' ' <<x3<<endl;
                if (!u[{x3, r-l+1}])
                    m[{x3, r-l+1}] = i, u[{x3, r-l+1}] = 1;
                else
                    if (m[{x3, r-l+1}] != i)
                        m[{x3, r-l+1}] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool rr = false;
        for (int len = 0; len < 9; len++)
        {
            if (rr)
                break;
            for (int l = 0; l +len < 9; l++)
            {
                int r = l + len;
                ll x1 = 1;
                for (int j = 0; j < 9-l; j++)
                    x1 *= 10;
                ll x2 = 1;
                for (int j = 0; j < 8-r; j++)
                    x2 *= 10;
                ll x3 = a[i] %x1 / x2;
                if (m[{x3, r-l+1}] == i)
                {
                    ll p = x3, pp = 0;
                    while (p > 0)
                    {
                        pp++;
                        p /= 10;
                    }
                    for (int u = 0; u < r-l+1-pp; u++)
                        cout<<'0';
                    if (x3 != 0)
                        cout << x3;
                    cout << endl;
                    rr = true;
                    break;
                }
            }
        }
    }
    return 0;
}