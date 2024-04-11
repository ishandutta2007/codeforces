#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
struct ura
{
    long long s,h,l;
    string v;
}v[100005];
bool cmp (ura a, ura b)
{
    return a.s*1LL*b.h>b.s*1LL*a.h;
}
string sf;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,tt,p,z;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].v;
            v[i].l=v[i].v.size();
            for(j=0;j<v[i].l;++j)
            {
                if(v[i].v[j]=='s')
                    ++v[i].s;
                else
                    ++v[i].h;
            }
        }
        sort(v+1,v+n+1,cmp);
        for(i=1;i<=n;++i)
            sf+=v[i].v;
        n=sf.size();
        long long s=0,sc=0;
        for(i=0;i<n;++i)
        {
            if(sf[i]=='s')
                ++sc;
            else
                s+=sc;
        }
        cout<<s;
    }
    return 0;
}