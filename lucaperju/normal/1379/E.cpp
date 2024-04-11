
#include <bits/stdc++.h>

using namespace std;

/*
long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int rz[100003];
void solve (int n, int k, int pz, int t)
{
    if(n==1)
    {
        assert(k==0);
        rz[pz]=t;
        return;
    }
    if(n==3)
    {
        assert(k==0);
        rz[pz]=t;
        solve(1,0,pz+1,pz);
        solve(1,0,pz+2,pz);
        return;
    }
    if(n==5)
    {
        assert(k==1);
        rz[pz]=t;
        solve(1,0,pz+1,pz);
        solve(3,0,pz+2,pz);
        return;
    }
    if(n==7)
    {
        assert(k==0 || k==2);
        if(k==0)
        {
            rz[pz]=t;
            solve(3,0,pz+1,pz);
            solve(3,0,pz+4,pz);
        }
        else
        {
            rz[pz]=t;
            solve(1,0,pz+1,pz);
            solve(5,1,pz+2,pz);
        }
        return;
    }
    if(n==9)
    {
        assert(k==1 || k==3);
        rz[pz]=t;
        solve(1,0,pz+1,pz);
        solve(7,k-1,pz+2,pz);
        return;
    }
    if(n==11)
    {
        assert(1<=k && k<=4);
        if(k==1)
        {
            rz[pz]=t;
            solve(3,0,pz+1,pz);
            solve(7,0,pz+4,pz);
            return;
        }
        if(k==2 || k==4)
        {
            rz[pz]=t;
            solve(1,0,pz+1,pz);
            solve(9,k-1,pz+2,pz);
            return;
        }
        if(k==3)
        {
            rz[pz]=t;
            solve(3,0,pz+1,pz);
            solve(7,2,pz+4,pz);
            return;
        }
        assert(0);
    }
    if(k>2)
    {
        rz[pz]=t;
        solve(1,0,pz+1,pz);
        solve(n-2,k-1,pz+2,pz);
        return;
    }
    if(k==0)
    {
        assert((n&(n+1))==0);
        rz[pz]=t;
        solve(n/2,0,pz+1,pz);
        solve(n/2,0,pz+n/2+1,pz);
        return;
    }
    if(k==1)
    {
        assert((n&(n+1))!=0);
        rz[pz]=t;
        for(int i=pz+1;i<pz+n;++i)
            rz[i]=pz+(i-pz+1)/2-1;
        return;
    }
    if(k==2)
    {
        if(((n-2)&(n-1))==0)
        {
            rz[pz]=t;
            solve(3,0,pz+1,pz);
            solve(n-4,1,pz+4,pz);
            return;
        }
        else
        {
            rz[pz]=t;
            solve(1,0,pz+1,pz);
            solve(n-2,1,pz+2,pz);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    cin>>n>>k;
    if(n%2==0)
    {
        cout<<"NO\n";
        return 0;
    }
    int mn=1;
    if((n&(n+1))==0)
        mn=0;
    int mx=max(0,(n-3)/2);
    if(mn==0 && k==1 || k<mn || mx<k || n==9 && k==2)
    {
        cout<<"NO\n";
        return 0;
    }
    solve(n,k,1,0);
    cout<<"YES\n";
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}