#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dst[203][203];
vector<int>v[203];
int dfs (int pz, int root, int t)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dst[root][v[pz][i]]=1+dst[root][pz];
        dfs(v[pz][i],root,pz);
    }
}
void add (long long &a, long long &b, long long x, long long y)
{
    long long ca=a;
    long long cb=b;
    a=(ca*1LL*y%mod+cb*1LL*x%mod)%mod;
    b=(cb*1LL*y)%mod;
}
void mul (long long &a, long long &b, long long x, long long y)
{
    a=(a*1LL*x)%mod;
    b=(b*1LL*y)%mod;
}
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=rz*1LL*a%mod;
        }
        else
        {
            exp>>=1;
            a=a*1LL*a%mod;
        }
    }
    return rz;
}
long long fct[203];
long long invfct[203];
long long put2[203];
long long cmb (long long n, long long k)
{
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
long long cmbv[203][203];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,k,x,b,i,n;
    cin>>n;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    put2[0]=1;
    put2[1]=2;
    for(i=2;i<=n;++i)
        put2[i]=2LL*put2[i-1]%mod;
    for(i=2;i<=n;++i)
        fct[i]=i*1LL*fct[i-1]%mod;
    for(i=2;i<=n;++i)
        invfct[i]=lgput(fct[i],mod-2);
    for(i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cmbv[i][j]=cmb(i,j);
    for(i=1;i<=n;++i)
        for(int j=i;j>=1;--j)
        {
            cmbv[i][j]=(cmbv[i][j]+cmbv[i][j+1])%mod;
        }
    for(i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dst[i][j]=1000;
    for(i=1;i<=n;++i)
    {
        dst[i][i]=0;
        dfs(i,i,-1);
    }
    long long sf=0,jf=0;
    for(a=n;a>=1;--a)
        for(b=a-1;b>=1;--b)
        {
            long long s=0,j=n;
            for(int c=1;c<=n;++c)
            {
                if(dst[c][b]>dst[c][a] && dst[c][b]-dst[c][a]==dst[a][b])
                    ++s;
            }
            for(int c=1;c<=n;++c)
            {
                if(dst[c][b]>dst[c][a] && dst[c][b]-dst[c][a]==dst[a][b]) continue;
                if(dst[c][a]>dst[c][b] && dst[c][a]-dst[c][b]==dst[a][b]) continue;
                long long sc=1,jc=n;
                long long dtoPath=(dst[c][a]+dst[c][b]-dst[a][b])/2;
                long long d1=dst[a][c]-dtoPath;
                long long d2=dst[b][c]-dtoPath;
                mul(sc,jc,cmbv[dst[a][b]-1][d1],put2[dst[a][b]-1]);
                add(s,j,sc,jc);
            }
            if(jf==0)
            {
                sf=s;
                jf=j;
            }
            else
                add(sf,jf,s,j);
        }
    cout<<sf*1LL*lgput(jf,mod-2)%mod<<'\n';
    return 0;
}