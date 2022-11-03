#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 20;
ll x , n , m , k;
ll t(ll a, ll b)
{
    if(a < 0)
        a = 0;
    return (a + b) * (b - a + 1) / 2;
}
void bs(ll l , ll r)
{
    if (l == r - 1)
    {
        x = t(r - (n - k), r - 1) + t(r - k + 1, r - 1);
        if (x + r <= m)
        {
            cout << r + 1;
            exit(0);
        }
        cout << l + 1;
        exit(0);
    }
    if (l == r)
    {
        cout << r + 1;
        exit(0);
    }
    ll mid = (l + r) / 2;
    x = t(mid - k + 1, mid - 1) + t(mid - (n - k), mid - 1) + mid;
    if (x <= m)
        bs(mid , r);
    else
        bs(l , mid);

}
int main()
{
    cin >> n >> m >> k;
    m -= n;
    bs(0 , m);
}