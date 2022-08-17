#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll f(ll a)
{
    if (a==1 || a==0) return 0;
    if (a==2) return 1;
    ll res = a*(a-1)/2;
    return res;
}

int main()
{
    ll d1[5000]={0}, d2[5000]={0};
    ll n,x,y,res=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y;
        d1[x+y-1]++;
        d2[x+1000-y]++;
    }
    for (int i=0;i<2006;i++)
    {
        res+=f(d1[i]) + f(d2[i]);
    }
    cout<<res;
    return 0;
}