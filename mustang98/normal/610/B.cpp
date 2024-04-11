#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap (a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll m[200001];
    ll m1[200001];
    ll ch=0,n, minn=10e10, maxx=-1;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>m[i];
        if (m[i]<minn) minn=m[i];
        m1[i]=-1;
    }
    //cout<<minn;
    for (int i=0;i<n;i++)
    {
        if (m[i]!=minn) ch++;
        else {m1[i]=ch; ch=0;}
    }
    if (ch)
    {
        ll i=0;
        while(m1[i]==-1) {i++; continue;}
        m1[i]+=ch;
    }
    for (int i=0;i<n;i++) maxx=max(maxx, m1[i]);
    cout<<maxx+minn*n;
    return 0;
}