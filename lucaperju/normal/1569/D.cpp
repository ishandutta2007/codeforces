#include <bits/stdc++.h>

using namespace std;


const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
int xs[200005];
int ys[200005];
int xx[1000006];
int yy[1000006],n,m;
struct ura
{
    int x,y;
}v[300005];
int cntx[200005],cnty[200005];
bool cmpx (ura a, ura b)
{
    if(a.x<b.x)
        return true;
    if(a.x>b.x)
        return false;
    return a.y<b.y;
}
bool cmpy (ura a, ura b)
{
    if(a.y<b.y)
        return true;
    if(a.y>b.y)
        return false;
    return a.x<b.x;
}
int findx (int x)
{
    int k=0;
    int pas=(1<<20);
    while(pas)
    {
        if(k+pas<=n && xs[k+pas]<=x)
            k+=pas;
        pas>>=1;
    }
    return k;
}
int findy (int x)
{
    int k=0;
    int pas=(1<<20);
    while(pas)
    {
        if(k+pas<=m && ys[k+pas]<=x)
            k+=pas;
        pas>>=1;
    }
    return k;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k;
    long long s=0;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(i=1;i<=n;++i){
            cin>>xs[i];
            xx[xs[i]]=1;
        }
        for(i=1;i<=m;++i){
            cin>>ys[i];
            yy[ys[i]]=1;
        }
        j=0;
        for(i=1;i<=k;++i)
        {
            cin>>v[++j].x>>v[j].y;
            if(xx[v[j].x] && yy[v[j].y])
                --j;
        }
        k=j;
        s=0;
        sort(v+1,v+k+1,cmpx);
        long long cntc=0;
        for(i=1;i<=k;++i)
        {
            ++cntc;
            if(!xx[v[i].x])
            {
                cntc=0;
                continue;
            }
            if(i==k || v[i+1].x!=v[i].x || findy(v[i+1].y)!=findy(v[i].y))
            {
                s=s-cntc*1LL*(cntc-1)/2LL;
                cntc=0;
            }
            ++cnty[findy(v[i].y)];
        }
        sort(v+1,v+k+1,cmpy);
        cntc=0;
        for(i=1;i<=k;++i)
        {
            ++cntc;
            if(!yy[v[i].y])
            {
                cntc=0;
                continue;
            }
            if(i==k || v[i+1].y!=v[i].y || findx(v[i+1].x)!=findx(v[i].x))
            {
                s=s-cntc*1LL*(cntc-1)/2LL;
                cntc=0;
            }
            ++cntx[findx(v[i].x)];
        }
        for(i=1;i<=n;++i)
        {
            s=s+cntx[i]*1LL*(cntx[i]-1)/2LL;
        }
        for(i=1;i<=m;++i)
        {
            s=s+cnty[i]*1LL*(cnty[i]-1)/2LL;
        }
        for(i=1;i<=n;++i)
        {
            cntx[i]=0;
            xx[xs[i]]=0;
        }
        for(i=1;i<=m;++i)
        {
            cnty[i]=0;
            yy[ys[i]]=0;
        }
        cout<<s<<'\n';
    }
    return 0;
}