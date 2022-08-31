#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;

bool prime(ll a)
{
    if (a==0 || a==1) return false;
    for (int i=2;i<=round(sqrt(a));i++) if(a%i==0) return false;
    return true;
}

ll qpow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b){
        if (b & 1){
            res = (res * (a % m)) % m;

        }
        a = (a % m) * (a % m);
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll a,b,n;
    string s;
    ll m[100005]={0};
    ll v[100005]={0};



    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    ll t=0;
    while(1)
    {
        if (t>=n || t<0) {cout<<"FINITE"; return 0;}
        if (v[t]) {cout<<"INFINITE"; return 0;}
        v[t]=1;
        if (s[t]=='>') t+=m[t];
        else t-=m[t];
    }

    return 0;
}