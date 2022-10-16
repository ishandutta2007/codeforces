#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
long long st[300005],sps[300005],spj[300005],v[3][300005];
int main()
{
    long long n,m,t,nrca,nrcb,i,j=1,ca,cb,mx=-99999999999999LL,mn=9999999999,s=0,k,x,y,z,nr0=0,nrb,ok=1,cur,cn,cnt=0,q,pred=0;
    cin>>n;
    for(i=1;i<=2;++i)
        for(j=1;j<=n;++j)
            cin>>v[i][j];
    for(i=n;i>=1;--i)
    {
        st[i]=st[i+1]+v[1][i]+v[2][i];
        sps[i]=sps[i+1]+st[i+1]+v[1][i]+v[2][i]*2LL*(n-i+1);
        spj[i]=spj[i+1]+st[i+1]+v[2][i]+v[1][i]*2LL*(n-i+1);
    }
    for(i=0;i<n;++i)
    {
        cur=pred;
        if(i%2==1)
            cur+=v[1][i]*1LL*(i*2LL-1)+v[2][i]*1LL*(i*2LL)+spj[i+1]+st[i+1]*2LL*i;
        else
            cur+=v[2][i]*1LL*(i*2LL-1)+v[1][i]*1LL*(i*2LL)+sps[i+1]+st[i+1]*2LL*i;
        if(cur>mx)
            mx=cur;
        if(i%2==1)
            pred+=v[1][i]*1LL*(i*2LL-1)+v[2][i]*1LL*(i*2LL);
        else
            pred+=v[2][i]*1LL*(i*2LL-1)+v[1][i]*1LL*(i*2LL);
    }
    cout<<mx-st[1];
    return 0;
}