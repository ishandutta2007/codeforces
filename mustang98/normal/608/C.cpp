#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll res=-5, n, kol=0, maxa=-5, a1, b1;
    ll a[1000001]={0};
    ll b[1000001]={0};
    ll m[1000001]={0};
    cin>>n;
    for (ll i=0;i<n;i++)
    {
        cin>>a1>>b1;
        maxa=max(maxa,a1);
        a[a1]=1;
        b[a1]=b1;
    }
    for (ll i=0;i<=maxa;i++)
    {
        if (a[i]==0) {if (i==0) m[i]=0; else m[i]=m[i-1]; continue;}
        if (i-b[i]-1 < 0) m[i]=1;
        else m[i]=1+m[i-b[i]-1];
        res=max(res,m[i]);
    }
    cout<<n-res;

    return 0;
}