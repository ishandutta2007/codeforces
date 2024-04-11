#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, sum = 0, a[100005], b[100005];
        bool c = true;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            sum += b[i];
        }
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % x)
                {
                    c = false;
                }
                else
                {
                    a[i] /= x;
                }
                if (c)
                    sum += b[i];
            }
            if (!c)
                break;
        }
        cout << sum << '\n';
    }
}