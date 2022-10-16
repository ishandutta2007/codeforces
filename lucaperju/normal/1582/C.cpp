#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
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
/*/
char v[100005];
int solve (int l, int r, char c)
{
    if(r<=l)
        return 0;
    if(v[l]==v[r])
        return solve(l+1,r-1,c);
    if(c==0)
    {
        int a=solve(l+1,r,v[l]);
        int b=solve(l,r-1,v[r]);
        if(a==-1 && b==-1)
            return -1;
        if(a==-1)
            return b+1;
        if(b==-1)
            return a+1;
        return min(a,b)+1;
    }
    else
    {
        if(v[l]!=c && v[r]!=c)
            return -1;
        if(v[l]==c)
        {
            int a=solve(l+1,r,c);
            if(a==-1)
                return a;
            return a+1;
        }
        else
        {
            int a=solve(l,r-1,c);
            if(a==-1)
                return a;
            return a+1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        cout<<solve(1,n,0)<<'\n';
    }
}