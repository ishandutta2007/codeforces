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
        ll n, sum = 0, one = 0, two = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                one++;
            else
                two++;
            sum += tmp;
        }
        if (sum % 4 == 0 || (sum % 2 == 0 && one >= 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}