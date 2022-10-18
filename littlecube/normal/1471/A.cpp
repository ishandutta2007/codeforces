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
        ll n, x, sum = 0, r = 0;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            r += (a + x - 1) / x;
            sum += a;
        }
        sum = (sum + x - 1) / x;
        cout << sum << " " << r << '\n';
    }
}