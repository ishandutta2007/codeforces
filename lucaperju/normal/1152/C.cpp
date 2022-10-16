#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod=1;
long long lgput (long long a, long long exp)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long cmmmc (long long a, long long b)
{
    return a*1LL*b/cmmdc(a,b);
}
bool verif (int val)
{
    for(int i=1;i<=20;++i)
        if((1<<i)-1==val)
            return true;
    return false;
}
int rz[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=(1LL<<62)-1+(1LL<<62),k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a,b;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    if(b%a==0)
    {
        cout<<0;
        return 0;
    }
    long long dif=b-a;
    for(i=1;i*i<=dif;++i)
    {
        if(dif%i==0)
        {
            long long ad=a%i;
            if(ad!=0)
                ad=i-ad;
            long long cur=cmmmc(a+ad,b+ad);
            if(cur<mn)
            {
                mn=cur;
                pz=ad;
            }
            ad=a%(dif/i);
            if(ad!=0)
                ad=dif/i-ad;
            cur=cmmmc(a+ad,b+ad);
            if(cur<mn)
            {
                mn=cur;
                pz=ad;
            }
        }
    }
    cout<<pz;
    return 0;
}