//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mo=1000000007;
int n,m;

ll power(int a,int b)
{
    if (b==0)   return 1;
    ll ans=power(a,b/2);
    ans*=ans;
    ans%=mo;
    if (b&1)    ans*=a;
    ans%=mo;
    return ans;
}
ll sum(int t)
{
    if (t&1)
    {
        ll ans=power(3,t/2);
        ans*=11;
        ans%=mo;
        ans-=7;
        ans%=mo;
        while (ans<0)   ans+=mo;
        return ans;
    }   else
    {
        ll ans=power(3,t/2-1);
        ans*=19;
        ans%=mo;
        ans-=7;
        ans%=mo;
        while (ans<0)   ans+=mo;
        return ans;
    }
}
ll calc(int t)
{
    if (t==0)   return 0;
    if (t==1)   return 4;
    ll ans=sum(t);
    ans+=sum((t+1)/2);
    ans%=mo;
    while (ans<0)   ans+=mo;
    ans*=500000004;
    ans%=mo;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    cout<<(calc(m)-calc(n-1)+mo)%mo<<endl;
    return 0;
}