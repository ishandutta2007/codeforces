#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N = 1e6+6;
const ll inf = 2e18;

ll n, k, q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans = 0;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n;
        return 0;
    }
    ll p = 1;
    while (p <= n)
        p *= 2;
    cout << p-1;
    return 0;
}