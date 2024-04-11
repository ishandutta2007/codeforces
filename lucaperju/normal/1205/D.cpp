#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
/*
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
vector<int>v[1003];
int sz[1003],n;
void dfssize (int pz, int t)
{
    sz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfssize(v[pz][i],pz);
        sz[pz]+=sz[v[pz][i]];
    }
}
int findcentroid (int pz, int t)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        if(sz[v[pz][i]]>n/2)
            return findcentroid(v[pz][i],pz);
    }
    return pz;
}
vector<int>vc;
bool cmp (int a, int b)
{
    return sz[a]<sz[b];
}
vector<int>first,second;
int val[1003];
int timpc;
void dfssmall (int pz, int t)
{
    ++timpc;
    int vt=val[t];
    cout<<pz<<' '<<t<<' '<<timpc-vt<<'\n';
    val[pz]=timpc;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfssmall(v[pz][i],pz);
    }
}
void dfsbig (int pz, int t, int incr)
{
    timpc+=incr;
    int vt=val[t];
    cout<<pz<<' '<<t<<' '<<timpc-vt<<'\n';
    val[pz]=timpc;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfsbig(v[pz][i],pz,incr);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,r,m,s,k,j,q;
    cin>>n;
    if(n==1)
    {
        return 0;
    }
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfssize(1,-1);
    int c=findcentroid(1,-1);
    dfssize(c,-1);
    for(i=0;i<v[c].size();++i)
        vc.push_back(v[c][i]);
    sort(vc.begin(),vc.end(),cmp);
    int cat=(n-2)/3+1;
    if(sz[vc.back()]>=cat)
    {
        first.push_back(vc.back());
        for(i=0;i<vc.size()-1;++i)
            second.push_back(vc[i]);
    }
    else
    {
        int sc=0;
        int ok=1;
        for(i=0;i<vc.size();++i)
        {
            sc+=sz[vc[i]];
            if(ok)
                first.push_back(vc[i]);
            else
                second.push_back(vc[i]);
            if(sc>=cat)
            {
                ok=0;
               // if(n==500)
               //     cout<<sc<<'!';
            }
        }
    }
    for(i=0;i<first.size();++i){
        //cout<<first[i]<<"!\n";
        dfssmall(first[i],c);
    }
    ++timpc;
    int timpci=timpc;
    timpc=0;
    for(i=0;i<second.size();++i)
        dfsbig(second[i],c,timpci);
    return 0;
}