#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
const long long mod=998244353;
long long lgput(long long n,long long p)
{
    long long rez=1LL;
    while(p)
    {
        if(p%2LL)
        {
            rez=(rez*1LL*n)%mod;
            p--;
        }
        else
        {
            p/=2LL;
            n=(n*1LL*n)%mod;
        }
    }
    return rez;
}
long long put[1000006];
int main()
{
    long long n,t,i,j=0,s=0,k=0,s1=0,s2=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,xcr,ycr,c,a,b,vl1=1,ok=0,sus=1,jos=1;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    a=1;
    for(i=1;i<=1000000;++i)
    {
        a=a*1LL*i;
        a%=mod;
        put[i]=a;
    }
    for(i=1;i<n-1;++i)
    {
        sus=i*1LL*put[n-1];
        sus%=mod;
        sus=sus*1LL*(n-i);
        sus%=mod;
        jos=put[i+1];
        jos=lgput(jos,998244351LL);
        jos=jos*1LL*sus;
        jos%=mod;
        s+=jos;
        s%=mod;
    }
    s++;
    s%=mod;
 /*   s+=2LL*n;
    s%=mod;
    s-=4LL;
    s+=mod;
    s%=mod;*/
    s=s*1LL*n;
    s%=mod;
    cout<<s;
}