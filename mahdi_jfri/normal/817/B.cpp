#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxn = 2e3 + 20;
map<ll , ll> mp;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int k = mp.begin() -> first;
    if(mp[k] > 2)
    {
        ll x = mp[k];
        cout << x * (x - 1) * (x - 2) / 6;
        return 0;
    }
    if(mp[k] == 2)
    {
        mp.erase(k);
        cout << mp.begin() -> second;
        return 0;
    }
    mp.erase(k);
    k = mp.begin() -> first;
    if(mp[k] > 1)
    {
        cout << mp[k] * (mp[k] - 1) / 2;
        return 0;
    }
    mp.erase(k);
    cout << mp.begin() -> second;
}