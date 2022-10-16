#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int v[1000006];
bool f[10000007],s[10000007];
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // srand ( time(NULL) );
    long long p,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b;
    long long ra,rb;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        v[i]=a;
        if(f[a]==false)
            f[a]=true;
        else
            s[a]=true;
    }
    for(i=1;i<=10000000;++i)
    {
        a=b=-1;
        for(j=i;j<=10000000 && a==-1;j+=i)
        {
            if(s[j])
                a=b=j;
            else
            if(f[j])
            {
                if(b==-1)
                    b=j;
                else
                    a=j;
            }
        }
        if(a!=-1 && b!=-1)
        {
            if(cmmmc(a,b)<mn)
            {
                mn=cmmmc(a,b);
                ra=a;
                rb=b;
            }
        }
    }
    long long oka=-1,okb=-1;
    for(i=1;i<=n;++i)
    {
        if(oka==-1 && v[i]==ra)
        {
            ra=i;
            oka=1;
        }
        else
        if(okb==-1 && v[i]==rb)
        {
            rb=i;
            okb=1;
        }
    }
    cout<<min(ra,rb)<<' '<<max(ra,rb);
    return 0;
}