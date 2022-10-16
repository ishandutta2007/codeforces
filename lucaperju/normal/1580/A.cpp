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
int v[404][404];
int sp[404][404];
int c0[404],c1[404];
int sp0[404];
int mnc[404];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long m,t,i,j,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                v[i][j]=c-'0';
                sp[i][j]=v[i][j]+sp[i-1][j];
            }
        int mn=n*m;
        mnc[0]=-n*m;
        for(int l1=1;l1<=n;++l1)
        {
            for(int l2=l1+4;l2<=n;++l2)
            {
                for(i=1;i<=m;++i)
                {
                    c0[i]=(v[l1][i]==0)+(v[l2][i]==0)+sp[l2-1][i]-sp[l1][i];
                    c1[i]=(l2-l1-1)-(sp[l2-1][i]-sp[l1][i]);
                    sp0[i]=c0[i]+sp0[i-1];
                }
                for(i=1;i<=m;++i)
                {
                    if(i>=4)
                        mn=min(mn,sp0[i-1]+c1[i]-mnc[i-3]);
                    mnc[i]=max(mnc[i-1],sp0[i]-c1[i]);
                }
            }
        }
        cout<<mn<<'\n';
    }
    return 0;
}