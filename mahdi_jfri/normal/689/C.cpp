#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll m , sum;
bool check(ll x)
{
    sum = 0;
    for(ll i = 2; i * i * i <= x; i++)
        sum += x / (i * i * i);
    return sum < m;
}
ll bs(ll l , ll r)
{
    if(r - l == 1)
    {

        if(check(r))
            return l;
        return r;
    }
    ll mid = (l + r) / 2;
    if(check(mid))
        return bs(mid , r);
    else
        return bs(l , mid);
}
int main()
{
    cin >> m;
    ll res = bs(1 , 1e18);
    if(sum != m)
    {
        cout << -1;
        return 0;
    }
    cout << res;
}