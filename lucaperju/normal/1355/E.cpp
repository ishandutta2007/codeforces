#include <bits/stdc++.h>

using namespace std;
long long v[100005],n;
long long sp[100005],sdr[100005],a,r,m;
long long check (long long val)
{
    int i;
    for(i=1;i<=n;++i)
    {
        if(v[i]==val)
            return 1000000000000000001LL;
        else if(v[i]<val && v[i+1]>val)
            break;
    }
    if(i==n+1)
        return 1000000000000000001LL;
    long long cstc=0;
    long long catcr=0;
    long long catsc=0;
    catcr=i*1LL*val-sp[i];
    catsc=sdr[i+1]-(n-i)*1LL*val;
    if(catcr>catsc)
    {
        cstc=(catcr-catsc)*1LL*a;
        catcr=catsc;
    }
    else
    {
        cstc=(catsc-catcr)*1LL*r;
        catsc=catcr;
    }
    cstc+=min(a+r,m)*1LL*catcr;
    return cstc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long i,t,j,k,mx,p,mxx=0,s,rz=0;
    cin>>n>>a>>r>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        sp[i]=sp[i-1]+v[i];
    for(i=n;i>=1;--i)
        sdr[i]=sdr[i+1]+v[i];
    rz=1000000000000000001LL;
    for(i=1;i<=n;++i)
    {
        long long cstc=0;
        long long catcr=0;
        long long catsc=0;
        catcr=i*1LL*v[i]-sp[i];
        catsc=sdr[i]-(n-i+1)*1LL*v[i];
        if(catcr>catsc)
        {
            cstc=(catcr-catsc)*1LL*a;
            catcr=catsc;
        }
        else
        {
            cstc=(catsc-catcr)*1LL*r;
            catsc=catcr;
        }
        cstc+=min(a+r,m)*1LL*catcr;
        rz=min(rz,cstc);
    }
    long long val=sp[n];
    rz=min(rz,check(val/n));
    rz=min(rz,check(val/n-1));
    rz=min(rz,check(val/n+1));
    rz=min(rz,check(val/n+2));
    rz=min(rz,check(val/n-2));
    cout<<rz;
    return 0;
}