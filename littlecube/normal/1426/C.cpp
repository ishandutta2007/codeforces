#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n;
        k = ceil(sqrt(n));
        if (k * (k - 1) >= n)
            cout << 2 * k - 3 << '\n';
        else
            cout << 2 * k - 2 << '\n';
    }
}