#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxn = 2e3 + 20;
ll s;
bool check(ll mid)
{
    ll k = mid , sum = 0;
    while(k)
    {
        sum += k % 10;
        k /= 10;
    }
    mid -= sum;
    return mid >= s;
}
ll bs(ll l , ll r)
{
    if(r - l == 1)
    {
        if(check(l))
            return l;
        return r;
    }
    ll mid = (r + l) / 2;
    if(check(mid))
        return bs(l , mid);
    return bs(mid , r);
}
int main()
{
    ll n;
    cin >> n >> s;
    if(!check(n))
    {
        cout << 0;
        return 0;
    }
    cout << max(n - bs(0 , 1e18) + 1 , 0LL);
}