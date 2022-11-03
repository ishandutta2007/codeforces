#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;
ll ans = 1 , a[maxn] , b[maxn];
int main()
{
    int n , k;
    cin >> n >> k;
    ll x = 1 , k2 = k;
    while(k2--)
        x *= 10;
    for(int i = 0; i < n / k; i++)
        cin >> a[i];
    for(int i = 0; i < n / k; i++)
        cin >> b[i];
    for(int i = 0; i < n / k; i++)
    {
        ll z = x / a[i] + 1 - (x % a[i] == 0);
        x /= 10;
        ll m = (a[i] - ((b[i] * x) % a[i])) % a[i];
        ll last = (x) / a[i] * a[i] + m;
        if(last >= x)
            last -= a[i];
        ll first = m;
        if(first >= x)
        {
            x *= 10;
            ans *= z;
            ans %= mod;
            continue;
        }
        z -= (last - first) / a[i] + 1;
        ans *= z;
        ans %= mod;
        x *= 10;
    }
    cout << ans;
}