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
vector<int>v;
bool check (long long l, long long a, long long b)
{
    if(l==2 || l==1)
        return true;
    a%=l;
    if(a>2)
        return false;
    if(a==0)
    {
        int r1=(b-1)%l;
        if(r1!=1)
            return false;
        return true;
    }
    else if(a==2)
    {
        if(b%l==0)
            return true;
        return false;
    }
    else
    {
        if(b%l==1)
            return true;
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,tt,p;
    cin>>t;
    //t=1;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long s=a+a+b+b-4;
        v.clear();
        for(i=1;i*i<=s;++i)
        {
            if(s%i)
                continue;
            if(check(i,a,b))
                v.push_back(i);
            if(s/i!=i)
            {
                if(check(s/i,a,b))
                    v.push_back(s/i);
            }
        }
        sort(v.begin(),v.end());
        cout<<v.size()<<' ';
        for(int i=0;i<v.size();++i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
    return 0;
}