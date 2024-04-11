#include <iostream>
#include <vector>
using namespace std;

#define ll long long

bool prime(ll n)
{
     for(ll i = 2; i * i <= n; ++i)
             if(n % i == 0)
                  return false;
     return true;
}

ll mult(vector<ll> & a, int left)
{
     ll ans = 1;
     for(int i = left; i < a.size(); ++i)
             ans *= a[i];
     return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n;
    
    cin >> n;
    
    if(prime(n))
                cout << n + 1ll;
    else
    {
        ll sum = 0, cur = n;
        vector<ll> div;
        
        for(ll i = 2; i * i <= n; ++i)
                    while(cur % i == 0)
                            div.push_back(i), cur /= i;
        if(cur > 1)
               div.push_back(cur);
               
        for(int i = 0; i < div.size(); ++i)
                sum += mult(div, i);
        
        cout << sum + 1ll;
    }
    
    return 0;
}