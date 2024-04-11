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
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a0=0,a1=0,a10,a11;
    cin>>n;
    while(!verif(n))
    {
        int cr=0;
        int cn=n;
        int cntc=0;
        while(cn%2==0)
        {
            cr=cr*2+1;
            ++cntc;
            cn/=2;
        }
        rz[++cnt]=cntc;
        n=n xor cr;
        if(verif(n))
        {
            ok=1;
            break;
        }
        ++n;
    }
    if(ok==0)
    cout<<cnt<<'\n';
    else
    cout<<cnt*2-1<<'\n';
    for(i=1;i<=cnt;++i)
        cout<<rz[i]<<' ';
    return 0;
}