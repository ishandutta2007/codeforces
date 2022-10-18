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
int n, m, k[300005], c[300005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll r = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> k[i];
        for (int i = 0; i < m; i++)
            cin >> c[i];
        sort(k, k + n, comp);
        for (int i = 0; i < n; i++)
        {
            if (k[i] > i + 1)
                r += c[i];
            else
                r += c[k[i]-1];
        }
        cout << r << '\n';
    }
}