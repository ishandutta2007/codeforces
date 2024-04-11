#include <bits/stdc++.h>

using namespace std;


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
const long long mod2=1000000007;
char v[262150];
long long cnt=0;
long long valA,valB,X;
pair<long long,long long> join (pair<long long,long long> l, pair<long long,long long> mid, pair<long long,long long> r, int cat)
{
    if(l>r)
        swap(l,r);
    pair<long long,long long>rz;
    rz.first=l.first;
    rz.second=l.second;

    rz.first=(rz.first*1LL*lgput(103,cat-1)%mod+mid.first)%mod;
    rz.first=(rz.first*1LL*lgput(103,cat-1)%mod+r.first)%mod;

    rz.second=(rz.second*1LL*lgput(97,cat-1)%mod+mid.second+1)%mod2;
    rz.second=(rz.second*1LL*lgput(107,cat-1)%mod+r.second+r.second)%mod2;

    return rz;
}
pair<long long,long long> dfs (long long pz, long long lv, long long mx)
{
    pair<long long,long long>myH;
    if(v[pz]=='A')
    {
        myH.first=valA;
        myH.second=(valA^X);
    }
    else
    {
        myH.first=valB;
        myH.second=(valB+X);
    }
    if(lv==mx)
        return myH;
    pair<long long,long long>l=dfs(pz<<1,lv+1,mx);
    pair<long long,long long>r=dfs((pz<<1)|1,lv+1,mx);
    if(l!=r)
    {
        ++cnt;
        //cout<<pz<<'\n';
    }
    return myH=join(l,myH,r,1<<(mx-lv));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,y,k,m,j=0,n,tt,p;
    srand(time(NULL));
    //cin>>t;
    t=1;
    while(t--)
    {
        valA=(rand()^rand())%25+1;  /// glhf hacking this
        valB=(rand()^rand())%25+1;
        while(valB==valA)
            valB=(rand()^rand())%25+1;
        X=(rand()^rand())%50;
        cin>>n;
        for(i=1;i<(1<<n);++i)
            cin>>v[i];
        dfs(1,1,n);
        cout<<lgput(2,cnt)<<'\n';
    }
    return 0;
}