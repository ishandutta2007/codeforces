//Author:mxh1999
//AC
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mo=1000000009;
int n,a,b;
ll ans;

ll zxy(int a,int b)
{
    ll hzh=1;
    for (int i=1;i<=a;i++)
    {
        hzh*=b-i;
        hzh%=mo;
    }
    for (int i=b;i>a;i--)
    {
        hzh*=i;
        hzh%=mo;
    }
    return hzh;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n-2;i++)
    if (i<=b && n-i<=a)
    {
        ll tmp=zxy(n-i-1,a);
        ll tmp2=zxy(i-1,b);
        ll sum=(tmp*tmp2)%mo;
        sum*=n-i-1;
        sum%=mo;
        ans+=sum;
        ans%=mo;
    }
    cout<<ans<<endl;
}