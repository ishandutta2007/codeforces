#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;


/*
const long long mod = 1000000007;

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
*/
struct ura
{
    int x,y,pz,t;
}v[200005];
int t[200005];
int tata (int pz)
{
    if(t[pz]==pz || t[pz]==0)
        return pz;
    return t[pz]=tata(t[pz]);
}
void join (int a, int b)
{
    a=tata(a);
    b=tata(b);
    if(a==b)
        return;
    t[a]=b;
}
bool cmp (ura a, ura b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp1 (ura a, ura b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
bool cmp2 (ura a, ura b)
{
    return a.pz<b.pz;
}
int vc[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,n,h,k,s=0,tt;
    long long i,j,m;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            t[i]=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].x>>v[i].y>>v[i].t;
            v[i].pz=i;
        }
        sort(v+1,v+n+1,cmp);
        for(i=2;i<=n;++i)
        {
            if(v[i].x==v[i-1].x && v[i].y-v[i-1].y<=k)
                join(v[i].pz,v[i-1].pz);
        }
        sort(v+1,v+n+1,cmp1);
        for(i=2;i<=n;++i)
        {
            if(v[i].y==v[i-1].y && v[i].x-v[i-1].x<=k)
                join(v[i].pz,v[i-1].pz);
        }
        sort(v+1,v+n+1,cmp2);
        for(i=1;i<=n;++i)
            v[tata(i)].t=min(v[tata(i)].t,v[i].t);
        j=0;
        for(i=1;i<=n;++i)
        {
            if(tata(v[i].pz)==v[i].pz)
            {
                vc[++j]=v[i].t;
            }
        }
        sort(vc+1,vc+j+1);
        int tc=0;
        for(i=j;i>=1;--i)
        {
            if(vc[i-1]<=tc)
            {
                cout<<tc<<'\n';
                break;
            }
            ++tc;
        }
    }
}