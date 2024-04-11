#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
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
long long vi[1000005];
long long dif[1000005];
long long rmq[21][1000005];
long long lg[1000005];
long long getcmmdc (long long a, long long b)
{
    int d=b-a+1;
    int lgc=lg[d];
    return cmmdc(rmq[lgc][b],rmq[lgc][a+(1<<lgc)-1]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    cin>>t;
    lg[0]=lg[1]=0;
    for(i=2;i<=1000000;++i)
        lg[i]=1+lg[i/2];
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>vi[i];
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        for(i=1;i<n;++i)
        {
            dif[i]=max(vi[i],vi[i+1])-min(vi[i],vi[i+1]);
            rmq[0][i]=dif[i];
        }
        for(int x=1;x<=19;++x)
            for(i=1;i<n;++i)
                rmq[x][i]=cmmdc(rmq[x-1][i],rmq[x-1][max(i-(1LL<<(x-1)),(1LL<<(x-1)))]);
        int l=1,r=1;
        int mx=1;
        for(;r<n;++r)
        {
            while(l<r && getcmmdc(l,r)==1)
                ++l;
            if(getcmmdc(l,r)>1)
            mx=max(mx,r-l+2);
        }
        cout<<mx<<'\n';
    }
    return 0;
}