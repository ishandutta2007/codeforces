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
int v[200005];
int aib[200005];
map<int,int>mp; /// tf is the point of -10^9<=ai<=10^9
int lsb (int x)
{
    return x&-x;
}
void upd (int pz, int val)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]+=val;
}
long long qry (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        mp.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            mp[v[i]]=1;
        }
        vector<int>vc;
        for(auto i : mp)
            vc.push_back(i.first);
        int cnt=0;
        for(i=0;i<vc.size();++i)
            mp[vc[i]]=++cnt;
        for(i=1;i<=n;++i)
            v[i]=mp[v[i]];
        long long s=0;
        for(i=1;i<=n;++i)
        {
           // long long qc=qry(v[i]-;
            //cout<<qry(v[i])<<' '<<qry(v[i]-1)<<"A\n";
            s+=min((i-1)-qry(v[i]),qry(v[i]-1));
            upd(v[i],1);
        }
        cout<<s<<'\n';
        for(i=1;i<=n;++i)
            upd(v[i],-1);
    }
    return 0;
}