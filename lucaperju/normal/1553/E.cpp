#include <bits/stdc++.h>

using namespace std;
/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
vector<int>rz;
int v[300005],fv[300005],vc[300005],viz[300005];

void dfs (int pz)
{
    viz[pz]=1;
    if(!viz[vc[pz]])
        dfs(vc[pz]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,i,j,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        rz.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            fv[i-1]=0;
        }
        for(i=1;i<=n;++i)
            ++fv[(i-v[i]+n)%n];
        for(int vlc=0;vlc<n;++vlc)
        {
            if(fv[vlc]<n-m-m)
                continue;
            for(i=1;i<=n;++i)
                vc[i]=(v[i]+vlc-1)%n+1,viz[i]=0;
            int cnt=0,cntc=0;
            for(i=1;i<=n;++i)
                if(!viz[i])
                {
                    ++cntc;
                    dfs(i);
                }
            if(n-cntc<=m)
                rz.push_back(vlc);
        }
        cout<<rz.size()<<' ';
        for(int i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}