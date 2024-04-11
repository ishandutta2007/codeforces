#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll n, k, v;
bool check(int x)
{
    ll sum = 0, q = 1;
    while (x / q > 0)
    {
        sum += x / q;
        q *= k;
    }
    //cout << x << ' ' << sum << endl;
    return sum >= n;
}
int main()
{
    cin >> n >> k;
    ll l = 0, r = 1000000000;
    while (l < r - 1)
    {
        ll m = (l+r)/2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}