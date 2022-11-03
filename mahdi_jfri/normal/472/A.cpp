#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+20;
bool isp[maxn];
int main()
{
    ll a;
    cin >> a;
    if(a%2 == 0)
    {
        cout << 4 << " " <<a-4;
        return 0;
    }
    for(ll i = 2 ; i < maxn ; i++)
    {
        if(!isp[i])
        {
            for(ll j = i*i ; j < maxn; j+=i)
            {
                    isp[j]=1;
            }
        }
    }
    for(ll i = a-2 ; i > 0 ; i--)
    {
        if(isp[i] && isp[a-i])
        {
            cout << i << " " << a-i;
            return 0;
        }
    }
}