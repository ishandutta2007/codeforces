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
vector<int>v[100005];
int xp[100005];
int a[100005];
int hask[100005];
int okt=0;
void dfs (int pz, int t)
{
    xp[pz]=a[pz];
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
        xp[pz]=(xp[pz]^xp[v[pz][i]]);
    }
}
int cntt=0;
void dfs1 (int pz, int t, int kk)
{
    hask[pz]=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs1(v[pz][i],pz,kk);
        hask[pz]=max(hask[pz],hask[v[pz][i]]);
    }
    if(hask[pz] && xp[pz]==0)
        okt=1;
    if(hask[pz]==0 && xp[pz]==kk && pz!=1)
        ++cntt;
    if(xp[pz]==kk)
        hask[pz]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,t,i,j,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        if(k==2)
        {
            if(xp[1]==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
            continue;
        }
        if(xp[1]==0)
        {
            cout<<"YES\n";
            continue;
        }
        int kk=xp[1];
        okt=0;
        cntt=0;
        dfs1(1,-1,kk);
        if(cntt>=2)
            okt=1;
        if(okt)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}