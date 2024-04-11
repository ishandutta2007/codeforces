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
/*
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
vector<int>vi[150003];
vector<int>v[150003];
int sz[150003];
bool cmp (int a, int b)
{
    return sz[a]<sz[b];
}
void dfsinit1 (int pz, int t)
{
    sz[pz]=1;
    for(int i=0;i<vi[pz].size();++i)
    {
        if(vi[pz][i]==t)
            continue;
        v[pz].push_back(vi[pz][i]);
        dfsinit1(vi[pz][i],pz);
        sz[pz]+=sz[vi[pz][i]];
    }
    sort(v[pz].begin(),v[pz].end(),cmp);
}
int pzs[150003],curtime;
int lastpz[150003];
void dfsinit2 (int pz, int t)
{
    pzs[pz]=++curtime;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfsinit2(v[pz][i],pz);
    }
    lastpz[pz]=curtime;
}
void add (int &a, int b)
{
    a+=b;
    if(a<0)
        a+=mod;
    if(mod<=a)
        a-=mod;
}
int aib[150003];
int lsb (int x)
{
    return x&-x;
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        add(rz,aib[i]);
    return rz;
}
void upd (int pz, int val)
{
    for(int i=pz;i<=150000;i+=lsb(i))
        add(aib[i],val);
}
void updlr (int l, int r, int val)
{
    upd(l,val);
    upd(r+1,-val);
}
vector<int>toUpdate;
int hasupd[150003];
int updval[150003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,n,m,j,k,q;
    cin>>n>>q;
    long long invn=lgput(n,mod-2);
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    dfsinit1(n,-1);
    dfsinit2(n,-1);
    int global = 0;
    while(q--)
    {
        long long a,pz,d;
        cin>>a>>pz;
        if(a==1)
        {
            cin>>d;
            add(updval[pz],d);
            if(!hasupd[pz])
                toUpdate.push_back(pz); /// such bs that this is needed
            hasupd[pz]=1;
            /*
            add(global,d);
            add(global,-((n-sz[pz])*1LL*d%mod*1LL*invn%mod));
            updlr(pzs[pz],lastpz[pz],(n-sz[pz])*1LL*d%mod*1LL*invn%mod);
            i=0;
            int pas;
            while(i<v[pz].size())
            {
                pas=(1<<17);
                k=i;
                while(pas)
                {
                    if(k+pas<v[pz].size() && sz[v[pz][k+pas]]==sz[v[pz][i]])
                        k+=pas;
                    pas>>=1;
                }
                updlr(pzs[v[pz][i]],lastpz[v[pz][k]],-(d*1LL*invn%mod*1LL*sz[v[pz][i]]%mod));
                i=k+1;
            }
            */
        }
        else
        {
            int cpz=pz;
            for(int x=0;x<toUpdate.size();++x)
            {
                pz=toUpdate[x];
                d=updval[pz];
                updval[pz]=0;
                hasupd[pz]=0;
                add(global,d);
                add(global,-((n-sz[pz])*1LL*d%mod*1LL*invn%mod));
                updlr(pzs[pz],lastpz[pz],(n-sz[pz])*1LL*d%mod*1LL*invn%mod);
                i=0;
                int pas;
                while(i<v[pz].size())
                {
                    pas=(1<<17);
                    k=i;
                    while(pas)
                    {
                        if(k+pas<v[pz].size() && sz[v[pz][k+pas]]==sz[v[pz][i]])
                            k+=pas;
                        pas>>=1;
                    }
                    updlr(pzs[v[pz][i]],lastpz[v[pz][k]],-(d*1LL*invn%mod*1LL*sz[v[pz][i]]%mod));
                    i=k+1;
                }
            }
            toUpdate.clear();
            int ans=global;
            add(ans,query(pzs[cpz]));
            cout<<ans<<'\n';
        }
    }
    return 0;
}