#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll a[maxn] , res , f;
int main()
{
    ll n , m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int k;
        cin >> k >> a[i];
    }
    sort(a + 1 , a + m + 1);
    reverse(a + 1 , a + m + 1);
    for(ll i = 1; i <= m; i++)
    {
        ll k = i * (i - 1) / 2;
        if(i % 2 == 0)
            k += i / 2 - 1; // Codeforces <= Shit
        if(k >= n)
        {
            if(i % 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if(f)
            res += a[i - 1] , f = 0;
        res += a[i];
    }
    cout << res;
}