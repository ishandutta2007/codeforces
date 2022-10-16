#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
/*/
int ciur[300004];
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>t;
    ciur[0]=ciur[1]=1;
    for(i=2;i<=300000;++i)
    {
        if(!ciur[i])
        {
            for(j=i*i;j<=300000;j+=i)
                ciur[j]=1;
        }
    }
    while(t--)
    {
        cin>>n;
        int s=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            s+=v[i];
        }
        if(ciur[s])
        {
            cout<<n<<'\n';
            for(i=1;i<=n;++i)
                cout<<i<<' ';
            cout<<'\n';
            continue;
        }
        for(i=1;i<=n;++i)
        {
            if(ciur[s-v[i]])
                break;
        }
        cout<<n-1<<'\n';
        for(j=1;j<=n;++j)
            if(j!=i)
                cout<<j<<' ';
        cout<<'\n';
    }
    return 0;
}