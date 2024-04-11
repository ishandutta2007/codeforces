#include <bits/stdc++.h>
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
    else if(cnt<0)
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
/*struct ura
{
    int val,id;
}a[1005];
bool cmp (ura a, ura b)
{
    if(a.val>b.val)
        return true;
    return false;
}*/
long long d[2][2005][2];
int main()
{
    // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    cin>>n>>k;
    d[0][1][0]=2;
    d[0][2][1]=2;
    --n;
    for(r=1;r<=n;++r)
    {
        i=r%2;
        ci=1-i;
        for(j=1;j<=k;++j)
        {
            d[i][j][0]=(d[ci][j][0]+d[ci][j][1]*2LL+d[ci][j-1][0])%998244353;
            d[i][j][1]=(d[ci][j-1][0]*2+d[ci][j][1])%998244353;
            if(j>=2)
            d[i][j][1]=(d[i][j][1]+d[ci][j-2][1])%998244353;
        }
    }
    cout<<(d[n%2][k][0]+d[n%2][k][1])%998244353;
    return 0;
}