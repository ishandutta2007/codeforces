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
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
char v[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    cin>>v;
    mx=v[0];
    pz=1;
    for(i=1;i<n;++i)
    {
        if(v[i]<mx)
        {
            cout<<"YES\n";
            cout<<pz<<' '<<i+1;
            return 0;
        }
        else
            mx=v[i],pz=i+1;
    }
    cout<<"NO";
    return 0;
}