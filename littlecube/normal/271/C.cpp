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
    int n, k;
    cin >> n >> k;
    if (n >= 3 * k && k != 1)
    {
        for (int i = 1; i <= k; i++)
            cout << (i % k + 1) << " ";
        for (int i = k + 1; i <= n; i++)
            cout << (i % k == 0 ? k : i % k) << " ";
    }
    else
        cout << -1;
}