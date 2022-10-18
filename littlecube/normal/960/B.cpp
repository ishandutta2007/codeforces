#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    ll n, k1, k2, k, a[1001], b[1001], e[1001] = {0}, r = 0;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        e[i] = abs(a[i] - b[i]);

    sort(e, e + n, comp);

    for (int i = 0; i < n; i++)
    {
        while (k > 0 && e[i] > e[i + 1])
        {
            if (k > i + 1)
            {
                k -= i + 1;
                for (int j = 0; j <= i; j++)
                    e[j]--;
            }
            else
            {
                for (int j = 0; j < k; j++)
                    e[j]--;
                k = 0;
            }
        }
    }
    if (k > 0)
        e[0] = k % 2;
    for (int i = 0; i < n; i++)
        r += e[i] * e[i];
    cout << r << '\n';
}