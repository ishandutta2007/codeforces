#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res , _max = -1e18;
vector<ll> v;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if(a % 2)
            v.pb(a);
        else if(a > 0)
            res += a;
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    for(auto x : v)
    {
        if(res % 2)
        {
            _max = max(res , _max);
        }
        res += x;
    }
    if(res % 2 == 0)
        res -= v.back();
    cout << max(_max , res);
}