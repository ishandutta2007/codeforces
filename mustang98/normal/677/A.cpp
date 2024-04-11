#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll a, b, n, h;
    ll m[10000]={0};
    cin>>n>>h;


    for (int i = 0; i < n;i++)
    {
        cin>>m[i];
    }
    ll ans = 0;
    for (int i = 0; i < n;i++)
        if (m[i]>h) ans+=2;
    else ans++;
    cout<<ans;
    return 0;
}