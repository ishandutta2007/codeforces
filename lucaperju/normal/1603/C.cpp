#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;

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
*/
int v[100003];
struct ura
{
    int val,cnt;
};
ura vc[100003];
ura aux[100003];
int fv[100003];
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); /// fk this problem
    long long m,q,t,s=0,n,d,j,i,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        s=0;
        k=0;
        for(i=n;i>=1;--i)
        {
            for(j=1;j<=k;++j)
            {
                s=(s+(v[i]-1)/vc[j].val*1LL*i%mod*1LL*vc[j].cnt%mod)%mod;
                fv[v[i]/((v[i]-1)/vc[j].val+1)]+=vc[j].cnt;
            }
            int ck=0;
            for(j=1;j<=k;++j)
            {
                if(fv[v[i]/((v[i]-1)/vc[j].val+1)])
                {
                    aux[++ck]={v[i]/((v[i]-1)/vc[j].val+1),fv[v[i]/((v[i]-1)/vc[j].val+1)]};
                    fv[v[i]/((v[i]-1)/vc[j].val+1)]=0;
                }
            }
            k=ck;
            for(j=1;j<=k;++j)
                vc[j]=aux[j];
            vc[++k]={v[i],1};
        }
        cout<<s<<'\n';
    }
    return 0;
}