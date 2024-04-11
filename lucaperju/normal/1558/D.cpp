#include <bits/stdc++.h>

using namespace std;


const long long mod = 998244353;
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

int aib[200005];
int a[200005],b[200005],prec[200005];
int has1[200005];
vector<int>willbenxt[200005];
vector<int>pzstoclear;
int whereupd[200005];

int lsb (int x)
{
    return x&-x;
}
void upd (int pz, int val)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]+=val;
}
int qry (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;++i)
            cin>>a[i]>>b[i];
        for(i=1;i<=m;++i)
            prec[i]=0,has1[i]=0;
        for(i=m;i>=1;--i)
        {
            /// find b[i]th zero
            int pas=1<<20;
            int k=0;
            while(pas)
            {
                if(k+pas<=n && k+pas-qry(k+pas)<b[i])
                    k+=pas;
                pas>>=1;
            }
            ++k;
            int p1=k;
            for(j=0;j<willbenxt[p1].size();++j)
                prec[willbenxt[p1][j]]=i;
            willbenxt[p1].clear();
            upd(p1,1);
            whereupd[i]=p1;
            /// find (b[i]-1)th zero
            if(b[i]==1)
                continue;
            pas=1<<20;
            k=0;
            while(pas)
            {
                if(k+pas<=n && k+pas-qry(k+pas)<b[i]-1)
                    k+=pas;
                pas>>=1;
            }
            ++k;
            willbenxt[k].push_back(i);
            pzstoclear.push_back(k);
        }
        int cnt=0;
        for(i=1;i<=m;++i)
        {
            ++cnt;
            has1[i]=1;
            if(has1[prec[i]])
            {
                has1[prec[i]]=0;
                --cnt;
            }
        }
        for(i=1;i<=m;++i)
            upd(whereupd[i],-1);
        for(int i=0;i<pzstoclear.size();++i)
            willbenxt[pzstoclear[i]].clear();
        pzstoclear.clear();
        cout<<cmb(n+n-1-cnt,n)<<'\n';
    }
    return 0;
}