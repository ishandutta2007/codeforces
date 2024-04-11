#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int mod;
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
long long v[300005],mxcp[300005],mxcpm[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    if(m>0)
    {
        long long s=0;
        for(i=1;i<=n;++i)
        {
            s+=v[i];
            if(s<0)
                s=0;
            mx=max(mx,s);
        }
        cout<<mx*1LL*m;
    }
    else
    {
        long long s=0;
        for(i=1;i<=n;++i)
        {
            s+=v[i];
            if(s<0)
                s=0;
            mxcp[i]=s;
        }
        s=0;
        for(i=1;i<=n;++i)
            mxcpm[i]=max(mxcpm[i-1]+v[i]*1LL*m,mxcp[i]);
        rz=max(0LL,mxcpm[n]);
        for(i=n;i>=1;--i)
        {
            s+=v[i];
            if(s<0)
                s=0;
            rz=max(rz,s+mxcpm[i-1]);
        }
        cout<<rz;
    }
    return 0;
}