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
long long a[300005],b[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(j=1;j<=m;++j)
        cin>>b[j];
    rz=0;
    for(i=2;i<=n;++i)
        rz=cmmdc(rz,a[i]-a[i-1]);
    for(i=1;i<=m;++i)
    {
        if(rz%b[i]==0)
        {
            cout<<"YES\n";
            cout<<(a[1]-1)%b[i]+1<<' '<<i;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}