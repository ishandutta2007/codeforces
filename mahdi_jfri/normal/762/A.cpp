#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<ll> v;
int main()
{
    ll n , k;
    cin >> n >> k;
    for(ll i = 1; i * i <= n; i++)
    {
        if(n % i)
            continue;
        v.pb(i);
        if(i * i == n)
            continue;
        v.pb(n / i);
    }
    sort(v.begin() , v.end());
    if(k > v.size())
        cout << -1;
    else
        cout << v[k - 1];
}