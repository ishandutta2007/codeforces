#include <bits/stdc++.h>

using namespace std;

/*
long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int fv[2];
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    cin>>t;
    while(t--)
    {
        fv[0]=fv[1]=0;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            v[i]=a%2;
            ++fv[v[i]];
        }
        if(max(fv[0],fv[1])-min(fv[0],fv[1])>=2)
        {
            cout<<"-1\n";
            continue;
        }
        long long cnt=0;
        for(i=1;i<=n;i+=2)
            ++cnt;
        long long mn=-1;
        if(cnt==fv[1])
        {
            long long cntc=0;
            j=1;
            for(i=1;i<=n;++i)
            {
                if(v[i]==1)
                {
                    cntc=cntc+max(i-j,j-i);
                    j+=2;
                }
            }
            if(mn==-1||cntc<mn)
                mn=cntc;
        }
        cnt=0;
        for(i=2;i<=n;i+=2)
            ++cnt;
        if(cnt==fv[1])
        {
            long long cntc=0;
            j=2;
            for(i=1;i<=n;++i)
            {
                if(v[i]==1)
                {
                    cntc=cntc+max(i-j,j-i);
                    j+=2;
                }
            }
            if(mn==-1||cntc<mn)
                mn=cntc;
        }
        cout<<mn<<'\n';
    }
    return 0;
}