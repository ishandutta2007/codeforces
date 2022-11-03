#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<pair<ll , ll> > ans;
int main()
{
    ll x;
    cin >> x;
    for(ll i = 1; ; i++)
    {
        ll a = i * i - (i) * (i - 1) / 2 , b = i * i * (i - 1) / 2 - (i) * (i - 1) * (2 * i - 1) / 6;
        if(x + b <= 0)
            break;
        if((x + b) % a)
            continue;
        ll y = (x + b) / a;
        if(y < i)
            break;
        ans.pb({i , y});
        if(i != y)
            ans.pb({y , i});
    }
    sort(ans.begin() , ans.end());
    cout << ans.size() << endl;
    for(auto a : ans)
        cout << a.first << " " << a.second << endl;
}