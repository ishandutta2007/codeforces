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
int aint[4000003],lazy[4000003];
void propag (int nod, int l, int r)
{
    aint[nod]+=lazy[nod];
    if(l!=r)
    {
        lazy[nod<<1]+=lazy[nod];
        lazy[(nod<<1)|1]+=lazy[nod];
    }
    lazy[nod]=0;
}
void upd (int nod, int l, int r, int ul, int ur, int val)
{
    propag(nod,l,r);
    if(r<ul || ur<l)
        return;
    if(ul<=l && r<=ur)
    {
        lazy[nod]+=val;
        propag(nod,l,r);
        return;
    }
    int mid=(l+r)/2;
    upd(nod<<1,l,mid,ul,ur,val);
    upd((nod<<1)|1,mid+1,r,ul,ur,val);
    aint[nod]=min(aint[nod<<1],aint[(nod<<1)|1]);
}
int query ()
{
    return aint[1];
}
struct ura
{
    int val,pz;
}v[1000003];
int b[1000003];
bool cmp (ura a, ura b)
{
    if(a.val==b.val)
        return a.pz<b.pz;
    return a.val<b.val;
}
int lsb (int x)
{
    return x&-x;
}
int n,aib[1000003];
void updaib (int pz, int val)
{
    for(int i=pz;i<=n;i+=lsb(i))
        aib[i]+=val;
}
int queryaib (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,q,t,i,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            aib[i]=0;
            cin>>v[i].val;
            v[i].pz=i;
        }
        for(i=1;i<=(n<<2);++i)
            aint[i]=lazy[i]=0;
        sort(v+1,v+n+1,cmp);
        long long s=0;
        for(i=n;i>=1;--i)
        {
            s=s+queryaib(v[i].pz);
            updaib(v[i].pz,1);
        }
        for(i=1;i<=m;++i)
            cin>>b[i];
        sort(b+1,b+m+1);
        long long sc=0;
        for(i=1;i<=n;++i)
        {
            if(v[i].val<b[1])
            {
                ++sc;
                upd(1,1,n,v[i].pz,n,-1);
            }
            else if(v[i].val>b[1])
            {
                upd(1,1,n,v[i].pz,n,1);
            }
        }
        for(i=1;i<=m;++i)
        {
            s=s+min(sc,sc+query());
            if(i<m && b[i+1]!=b[i])
            {
                int k=0,pas=1<<20;
                while(pas)
                {
                    if(k+pas<=n && v[k+pas].val<b[i])
                        k+=pas;
                    pas>>=1;
                }
                ++k;
                while(k<=n && v[k].val<b[i+1])
                {
                    ++sc;
                    if(v[k].val==b[i])
                        upd(1,1,n,v[k].pz,n,-1);
                    else
                        upd(1,1,n,v[k].pz,n,-2);
                    ++k;
                }
                while(k<=n && v[k].val==b[i+1])
                {
                    upd(1,1,n,v[k].pz,n,-1);
                    ++k;
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
 /// nice fking problem