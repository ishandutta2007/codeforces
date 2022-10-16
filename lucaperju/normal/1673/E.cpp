#include <bits/stdc++.h>

using namespace std;


const long long mod = 2;

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
long long fct[1048580],invfct[1048580],inv[1048580];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return ((k&n)==k);
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=1048576;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}

int rz[1048580],v[1048580],k;
long long sp[1048580];
int idk[3][40];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,tt,p,n,K;
    init();
    cin>>n>>k;
    for(i=0;i<=min(30LL,n);++i)
    {
        for(j=k;j<=n-1-i;++j)
            idk[0][i]^=(cmb(n-1-i,j))%2;
        --k;
        for(j=k;j<=n-1-i;++j)
            idk[1][i]^=(cmb(n-1-i,j))%2;
        --k;
        for(j=k;j<=n-1-i;++j)
            idk[2][i]^=(cmb(n-1-i,j))%2;
        k+=2;
    }
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        sp[i]=sp[i-1]+v[i];
    for(int l=1;l<=n;++l)
    {
        for(int r=l;r<=n && sp[r]-sp[l]<=20;++r)
        {
            long long vlc=(1<<(sp[r]-sp[l]))*1LL*v[l];
            if(vlc>1048580)
                continue;
            if(idk[(l!=1)+(r!=n)][n-1-(l-1-(l!=1)+n-r-(r!=n))])
                rz[vlc]^=1;
        }
    }
    for(i=1048576-1;i>=0 && rz[i]==0;--i);
    if(i==-1)
    {
        cout<<0;
        return 0;
    }
    for(;i>=0;--i)
        cout<<rz[i];
    return 0;
}