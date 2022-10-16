#include <bits/stdc++.h>

using namespace std;


struct ura
{
    long long val,pz;
}vi[200005];
long long v[200005];
bool cmp (ura a, ura b)
{
    if(a.val==b.val)
        return a.pz>b.pz;
    return a.val<b.val;
}
long long lsb (long long x)
{
    return x&-x;
}
const long long mod=1000000007;
long long dp[200005],mxp[200005];
long long aib1[200005];
void upd1 (long long pz, long long val)
{
    for(long long i=pz;i<=200000;i+=lsb(i))
    {
        aib1[i]+=val;
        if(aib1[i]>mod)
            aib1[i]-=mod;
    }
}
long long query1 (long long pz)
{
    long long rz=0;
    for(long long i=pz;i>0;i-=lsb(i))
    {
        rz+=aib1[i];
        if(rz>mod)
            rz-=mod;
    }
    return rz;
}
struct ura1
{
    long long poz,cnt;
}aib[200005];
void combine (ura1& a, ura1 b)
{
    if(a.poz>b.poz)
        return;
    if(b.poz>a.poz)
        a=b;
    else
    {
        a.cnt+=b.cnt;
        if(a.cnt>mod)
            a.cnt-=mod;
    }
}
void upd (long long pz, ura1 val)
{
    for(long long i=pz;i<=200000;i+=lsb(i))
        combine(aib[i],val);
}
ura1 query (long long pz)
{
    ura1 rz={0,0};
    for(long long i=pz;i>0;i-=lsb(i))
        combine(rz,aib[i]);
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>vi[i].val;
            vi[i].pz=i;
            aib1[i]=0;
            aib[i]={0,0};
        }
        sort(vi+1,vi+n+1,cmp);
        for(i=1;i<=n;++i)
            v[vi[i].pz]=i;
        for(i=1;i<=n;++i)
        {
            dp[i]=1+query1(v[i]);
            if(dp[i]>mod)
                dp[i]-=mod;
            upd1(v[i],dp[i]);
        }
        mxp[n+1]=0;
        for(i=n;i>=1;--i)
        {
            aib1[i]=0;
            mxp[i]=max(mxp[i+1],v[i]);
        }
        long long s=0;
        for(i=n;i>=1;--i)
        {
            long long vlc=1+query1(n+1-v[i]);
            if(vlc>mod)
                vlc-=mod;
            upd1(n+1-v[i],vlc);
            if(v[i]>mxp[i+1])
            {
                upd(n+1-v[i],{i,1});
                continue;
            }
            ura1 a=query(n+1-v[i]);
            s+=((vlc-a.cnt+mod)%mod)*1LL*dp[i]%mod;
            if(s>mod)
                s-=mod;
            upd(n+1-v[i],a);
        }
        cout<<s<<'\n';
    }
}