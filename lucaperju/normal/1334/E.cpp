#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long cmmdc (long long a, long long b)
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
long long cmb[55][55];
long long factpsb[50],expn[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n,s=0,a,b,ok;
    long long k=0,t,d;
    cin>>d>>n;
    for(i=2;i*i<=d;++i)
    {
        if(d%i==0)
        {
            factpsb[++k]=i;
            while(d%i==0)
                d/=i;
        }
    }
    if(d!=1)
        factpsb[++k]=d;
    cmb[0][0]=cmb[1][0]=cmb[1][1]=1;
    for(i=2;i<=50;++i)
    {
        cmb[i][0]=1;
        for(j=1;j<=i;++j)
            cmb[i][j]=(cmb[i-1][j-1]+cmb[i-1][j])%mod;
    }
    for(i=1;i<=n;++i)
    {
        long long a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<1<<'\n';
            continue;
        }
        long long cmdc=cmmdc(a,b);
        long long ad=b/cmdc;
        long long scs=a/cmdc;
        long long rz=1;
        ///ad
        int sc=0;
        for(j=1;j<=k;++j)
        {
            expn[j]=0;
            while(ad%factpsb[j]==0)
                ++expn[j],ad/=factpsb[j];
            sc+=expn[j];
        }
        for(j=1;j<=k;++j)
        {
            rz=(rz*1LL*cmb[sc][expn[j]])%mod;
            sc-=expn[j];
        }
        sc=0;
        for(j=1;j<=k;++j)
        {
            expn[j]=0;
            while(scs%factpsb[j]==0)
                ++expn[j],scs/=factpsb[j];
            sc+=expn[j];
        }
        for(j=1;j<=k;++j)
        {
            rz=(rz*1LL*cmb[sc][expn[j]])%mod;
            sc-=expn[j];
        }
        cout<<rz<<'\n';
    }
    return 0;
}