#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

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
long long v[200003];
vector<long long>vc;
bool eprim (long long a)
{
    for(long long i=2;i*i<=a;++i)
        if(a%i==0)
            return false;
    return true;
}
long long solve ()
{
    long long lst=0,cur=0,s=0;
    for(long long i=0;i<vc.size();++i)
    {
        if(!eprim(vc[i]))
        {
            lst=cur=0;
            continue;
        }
        ++cur;
        if(vc[i]!=1)
        {
            lst=cur;
            --s;
            cur=0;
        }
        s+=lst;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,k,j,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long cnt=0;
        for(j=1;j<=min(k,n);++j)
        {
            vc.clear();
            for(i=j;i<=n;i+=k)
                vc.push_back(v[i]);
            cnt+=solve();
        }
        cout<<cnt<<'\n';
    }
    return 0;
}