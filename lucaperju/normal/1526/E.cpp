#include <bits/stdc++.h>
using namespace std;
int pz[200003];
int v[200003];
const int mod=998244353;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=rz*1LL*a%mod;
        }
        else
        {
            exp>>=1;
            a=a*1LL*a%mod;
        }
    }
    return rz;
}
long long fct[400003];
long long invfct[400003];
long long cmb (long long n, long long k)
{
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,k,n;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>pz[i];
        ++pz[i];
        v[pz[i]]=i;
    }
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=k+n;++i)
    {
        fct[i]=i*1LL*fct[i-1]%mod;
    }
    invfct[k+n]=lgput(fct[k+n],mod-2);
    for(i=k+n-1;i>=2;--i)
    {
        invfct[i]=invfct[i+1]*1LL*(i+1)%mod;
    }
    --k;
    int cnt=0;
    for(i=1;i<n;++i)
    {
        if(v[pz[i]+1]>v[pz[i+1]+1])
            ++cnt;
    }
    if(k<cnt)
    {
        cout<<0;
        return 0;
    }
    long long rz;
    k-=cnt;
    rz=cmb(n+k,k);
    cout<<rz;
	return 0;
}