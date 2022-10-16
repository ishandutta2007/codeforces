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
char vi[55][55];
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        long long n,m,k;
        cin>>n>>m>>k;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j){
                cin>>vi[i][j];
                v[i][j]=0;
            }
        for(i=k+1;i<=n;++i)
        {
            for(j=k+1;j+k<=m;++j)
            {
                if(vi[i][j]=='*')
                {
                    int cnt;
                    for(cnt=1;cnt<=k;++cnt)
                        if(vi[i-cnt][j-cnt]=='.' || vi[i-cnt][j+cnt]=='.')
                            break;
                    if(cnt<=k)
                        continue;
                    cnt=1;
                    ++v[i][j];
                    while(i-cnt>=1 && j-cnt>=1 && j+cnt<=m)
                    {
                        if(vi[i-cnt][j-cnt]=='.' || vi[i-cnt][j+cnt]=='.') break;
                        ++v[i-cnt][j-cnt];
                        ++v[i-cnt][j+cnt];
                        ++cnt;
                    }
                }
            }
        }
        int ok=1;
        for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(vi[i][j]=='*' && v[i][j]==0)
                ok=0;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}