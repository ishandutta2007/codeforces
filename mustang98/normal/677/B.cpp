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
    ll a, b, n, k,H;
    ll m[1000009]={0};
    cin>>n>>H>>k;


    for (int i = 0; i < n;i++)
    {
        cin>>m[i];
    }
    ll cur = 0;
    ll ans = 0;
    ll h=0;
    while (true)
    {
        if (h == 0 && cur >=n) break;
        while (cur<n && h+m[cur] <= H)
        {
            h+=m[cur];
            cur++;
        }
        if (h/k >= 1)
        {
            ans+=(h/k);
            h%=k;
        }
        else {h=0;ans++;}
    }
    cout<<ans;
    return 0;
}