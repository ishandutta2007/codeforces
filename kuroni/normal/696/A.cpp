

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> point;
ll ans;
ll trail(ll v, ll u, ll w)
{
    ans = 0;
    while (v != u)
    {
        if (u<v) swap(v,u);
        ans += point[u];
        point[u] += w;
        u /= 2;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    ll q,e,u,v,w;
    cin>>q;
    while (q--)
    {
        cin>>e>>u>>v;
        if (e == 1)
        {
            cin>>w;
            trail(u,v,w);
        }
        else
        {
            trail(u,v,0);
            cout<<ans<<endl;
        }    
    }
}