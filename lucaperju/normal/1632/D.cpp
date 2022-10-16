#include <bits/stdc++.h>

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
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int v[200005],rmq[200005][20];
int lg[200005],nxt[200005],rz[200005];
int getlr (int a, int b)
{
    return cmmdc(rmq[b][lg[b-a+1]],rmq[a+(1<<(lg[b-a+1]))-1][lg[b-a+1]]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,m,j=0,n,s=0,t;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        rmq[i][0]=v[i];
    }
    lg[1]=0;
    for(i=2;i<=n;++i)
        lg[i]=1+lg[i>>1];
    for(int put=1;put<=18;++put)
        for(i=1;i<=n;++i)
            rmq[i][put]=cmmdc(rmq[i][put-1],rmq[max(1LL,i-(1<<(put-1)))][put-1]);
    for(i=1;i<=n;++i)
    {
        nxt[i]=-1;
        k=0;
        int pas=1<<18;
        while(pas)
        {
            if(i+k+pas<=n && getlr(i,i+k+pas)>=k+pas+1)
                k+=pas;
            pas>>=1;
        }
        if(getlr(i,i+k)==k+1)
            nxt[i]=i+k;
    }
    for(i=1;i<=n;++i)
    {
        if(nxt[i]!=-1)
        {
            ++rz[nxt[i]];
            i=nxt[i];
        }
    }
    for(i=1;i<=n;++i)
    {
        s+=rz[i];
        cout<<s<<' ';
    }
    return 0;
}