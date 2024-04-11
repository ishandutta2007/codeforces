#include <bits/stdc++.h>

using namespace std;

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

int v[5005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
   // cin>>t;
   t=1;
    init();
    while(t--)
    {
        cin>>n>>k;
        s=1;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        int ok=0;
        for(int pz1=1;pz1<=n;++pz1)
        {
            if(v[pz1]!=1)
                continue;
            int l;
            for(l=pz1-1;l>=1 && v[l]==0;--l);
            ++l;
            int cnt=1;
            for(i=pz1+1;i<=n;++i)
            {
                if(v[i]==1)
                    ++cnt;
                if(cnt>k)
                {
                    --i;
                    --cnt;
                    break;
                }
            }
            if(cnt==k)
                ok=1;
            i=min(i,n);
            //if(cnt<k)
            //    break;
            int r=i;
            for(i=l;i<=r-cnt+1;++i)
            {
                if(i==pz1)
                    continue;
                s=(s+cmb(r-i,cnt-1))%mod;
            }
        }
        if(!ok)
            s=1;
        cout<<s<<'\n';
    }
}