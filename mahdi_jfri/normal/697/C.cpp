#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
ll solve(ll v , ll u , ll w)
{
    ll ans = 0;
    while(v != u)
    {
        if(u < v)
            swap(v,u);
        ans += mp[u];
        mp[u] += w;
        u/=2;
    }
    return ans;
}
ll a, b ,c ,d;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c >> d;
            solve(b,c,d);
        }
        else
        {
            cin >> b >> c;
            cout << solve(b,c,0) << endl;
        }
    }
}