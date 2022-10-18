#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        long n, a[200005], r[200005], m = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
            if (i + a[i] < n)
                r[i] = a[i] + r[i + a[i]];
            else
                r[i] = a[i];
        for (int i = 0; i < n; i++)
            m = max(m, r[i]);
        cout << m << '\n';
    }
    return 0;
}