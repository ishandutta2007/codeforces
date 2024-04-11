#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;
ll t(ll a , ll b)
{
    if(!b)
        return 1;
    ll x = t(a , b / 2);
    x = (x * x) % mod;
    if(b & 1)
        x *= a;
    return x % mod;
}
int main()
{
    ll a , b , n , x;
    cin >> a >> b >> n >> x;
    if(a == 1)
    {
        cout << (x + (((n % mod) * b) % mod)) % mod;
        return 0;
    }
    ll res = (t(a , n) * x) % mod , c = ((t(a , n) - 1) * t(a - 1 , mod - 2)) % mod;
    c = (c * b) % mod;
    cout << (res + c) % mod << endl;
}