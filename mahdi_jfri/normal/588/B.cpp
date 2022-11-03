#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n;
    scanf("%I64d" , &n);
    ll ans = n;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            n /= i;
            while(n % i == 0)
            {
                ans /= i;
                n /= i;
            }
        }
    }
    printf("%I64d" , ans);
}