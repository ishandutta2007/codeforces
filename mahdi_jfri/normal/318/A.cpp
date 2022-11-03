#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+20;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll odd=n/2;
    if(n%2)
        odd++;
    if(n==k && n==1)
    {
        cout<<1;
        return 0;
    }
    if(k>odd)
    {
        k-=odd;
        cout<<2*(k);
    }
    else
    {
        cout<<2*k-1;
    }
}