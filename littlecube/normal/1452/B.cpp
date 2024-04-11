#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, sum = 0, m = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ll tmp;
            cin >> tmp;
            m = max(m, tmp);
            sum += tmp;
        }
        cout << max(m * (n - 1) - sum, (sum % (n - 1) == 0 ? 0 : (n - 1) - (sum % (n - 1)))) << '\n';
    }
}