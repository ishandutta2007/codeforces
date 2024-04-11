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
int v[1000006];
int cnt[1000006];
int viz[1000006];
int rz[1000006];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;
        for(i=0;i<n;++i)
        {
            viz[i]=rz[i]=0;
            cin>>v[i];
        }
        int gcd=cmmdc(n,d);
        for(i=0;i<gcd;++i)
            cnt[i]=0;
        for(i=0;i<n;++i)
            cnt[i%gcd]+=1-v[i];
        for(i=0;i<gcd;++i)
            if(cnt[i]==0)
                break;
        if(i<gcd)
        {
            cout<<"-1\n";
            continue;
        }
        int mx=0;
        for(i=0;i<n;++i)
        {
            if(!viz[i])
            {
                int pz=i;
                int cntc=0;
                while(!viz[pz] && v[pz]==1)
                {
                    ++cntc;
                    viz[pz]=1;
                    pz=(pz-d+n)%n;
                }
                cntc+=rz[pz];
                mx=max(mx,cntc);
                rz[i]=cntc;
            }
        }
        cout<<mx<<'\n';
    }
    return 0;
}