#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long v[300005];
long long sp[300005];
bool cmp (long long a, long long b)
{
    return a>b;
}
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1LL)
        {
            --exp;
            rz=(rz*1LL*a)%mod;
        }
        else
        {
            exp>>=1LL;
            a=(a*1LL*a)%mod;
        }
    }
    return rz;
}
int main()
{
    long long n,m,i,j,x,y,k;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
        sp[i]=(v[i]+sp[i-1])%mod;
    for(k=1;k<=n;++k)
    {
        long long pz=k;
        long long s=0;
        long long vlc=0;
        while(1)
        {
            s+=((sp[min(n,pz)]-sp[pz-k])+mod)%mod*1LL*vlc%mod;
            s%=mod;
            if(pz>n)
                break;
            pz+=k;
            ++vlc;
        }
        cout<<(s*1LL*lgput(n,mod-2))%mod<<' ';
    }
    return 0;
}