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
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int v[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a0=0,a1=0,a10,a11;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        a0+=(a%2==0);
        a1+=(a%2==1);
    }
    for(i=1;i<=m;++i)
    {
        int a;
        cin>>a;
        if(a%2==0)
        {
            if(a1)
            {
                --a1;
                ++cnt;
            }
        }
        else
        {
            if(a0)
            {
                --a0;
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;
}