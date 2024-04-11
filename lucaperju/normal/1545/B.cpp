#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int v[100005];
int fct[100005],invfct[100005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp--;
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
long long cmb (long long n, long long k)
{
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q,m,i,j,l,r,t,n;
    cin>>t;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=100000;++i)
        fct[i]=i*1LL*fct[i-1]%mod;
    for(i=2;i<=100000;++i)
        invfct[i]=lgput(fct[i],mod-2);
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        int cnt=0,nn=n;
        for(i=2;i<=n;++i)
        {
            if(v[i]==1 && v[i-1]==1)
            {
                v[i]=v[i-1]=0;
                ++cnt;
                --nn;
            }
        }
        for(i=1;i<=n;++i)
            nn-=v[i];
        cout<<cmb(nn,cnt)<<'\n';
    }
    return 0;
}