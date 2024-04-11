#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
const int maxn = 2e5 + 20;
const ll mod = 1e9 + 7;
ll pw(ll a , ll b)
{
    if(!b)
        return 1;
    ll x = pw(a , b / 2);
    x = (x * x) % mod;
    if(b & 1)
        x *= a;
    return x % mod;
}
ll t[maxn] , res = 1 , n = 1 , l;
int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        t[x]++;
        n *= x;
        n %= mod;
    }
    bool f = 0 , f1 = 1;
    res = n;
    for(int i = 0; i < maxn; i++)
    {
        if(f1 && t[i] % 2)
            res = pw(res , (t[i] + 1) / 2) , f1 = 0;
        else
            res = pw(res , t[i] + 1);
        res %= mod;
    }
    if(!f1)
    {
        cout << res << endl;
        return 0;
    }
    else
    {
        vector<int> v;
        for(int i = 0; i < maxn; i++)
            if(t[i])
                v.pb(i);
        ll k = n;
        res = 1;
        for(auto x : v)
        {
            res *= pw(k , (t[x] + 1) / 2);
            res %= mod;
            k = pw(k , t[x] + 1);
        }
        n = 1;
        for(auto i : v)
        {
            n *= pw(i , t[i] / 2);
            n %= mod;
        }
        res *= n;
        res %= mod;
        cout << res << endl;
    }
}