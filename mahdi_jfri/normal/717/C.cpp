#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
const int mod=1e4+7;
ll a[maxn];
ll res=0;
int main()
{
    ll n;
    cin >> n;
    for(ll i=0; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    for(ll i=0; i < n; i++)
        res=(res+a[i]*a[n-i-1])%mod;
    cout<<res;
}