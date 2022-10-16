#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
int cmmdc (int a, int b)
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
long long cmmmc (int a, int b)
{
    return a*1LL*b/cmmdc(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // srand ( time(NULL) );
    long long p,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    int cn=n;
    for(i=2;i*i<=cn;++i)
    {
        if(cn%i==0)
        {
            if(dv==-1)
                dv=i;
            else
                ok=1,dv1=i;
            while(cn%i==0)
                cn/=i;
        }
    }
    if(cn!=1)
    {
        i=cn;
        if(cn%i==0)
        {
            if(dv==-1)
                dv=i;
            else
                ok=1,dv1=i;
            while(cn%i==0)
                cn/=i;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n2\n";
    cn=n-1;
    while(cn%dv1!=0)
    {
        cn-=dv;
        ++cnt;
    }
    cout<<cnt<<' '<<n/dv<<'\n';
    cout<<cn/dv1<<' '<<n/dv1<<'\n';
    return 0;
}