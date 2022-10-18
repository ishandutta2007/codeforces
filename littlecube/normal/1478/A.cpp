#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, r = 0;
        map<int, int> m;
        cin >> n;
        while(n--)
        {
            int x;
            cin >> x;
            m[x]++;
            r = max(r, m[x]);
        }
        cout << r << '\n';
    }

    return 0;
}