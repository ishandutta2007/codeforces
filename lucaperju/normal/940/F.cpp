#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
const int bucket = 4308;
map<int,int>mp;
struct query
{
    int l,r,t,pz;
}qs[100003];
struct update
{
    int p,newval,oldval;
}upds[100003];
int v[100003],aux[100003];
bool cmp (query a, query b)
{
    if(a.l/bucket == b.l/bucket)
    {
        if(a.r/bucket == b.r/bucket)
            return a.t<b.t;
        return a.r<b.r;
    }
    return a.l<b.l;
}
int rz[100003];
int fv[300003];
int fvfv[300003];
void add (int val)
{
    if(fv[val])
        --fvfv[fv[val]];
    ++fv[val];
    ++fvfv[fv[val]];
}
void rem (int val)
{
    --fvfv[fv[val]];
    --fv[val];
    if(fv[val])
        ++fvfv[fv[val]];
}
int getans ()
{
    for(int i=1;1;++i)
        if(!fvfv[i])
            return i;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,n,m,j,k,q;
    cin>>n>>q;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        aux[i]=v[i];
        mp[v[i]]=1;
    }
    int cntu=0,cntq=0;
    for(i=1;i<=q;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            qs[++cntq]={b,c,cntu,cntq};
        else
        {
            upds[++cntu]={b,c,aux[b]};
            aux[b]=c;
            mp[c]=1;
        }
    }
    int cnt=0;
    vector<int>vc;
    for(auto i : mp)
        vc.push_back(i.first);
    for(auto i : vc)
        mp[i]=++cnt;
    for(i=1;i<=n;++i)
    {
        v[i]=mp[v[i]];
        assert(v[i] != 0);
    }
    for(i=1;i<=cntu;++i)
    {
        upds[i].newval=mp[upds[i].newval];
        upds[i].oldval=mp[upds[i].oldval];
        assert(upds[i].newval != 0);
        assert(upds[i].oldval != 0);
    }
    sort(qs+1,qs+cntq+1,cmp);
    int T=0,L=1,R=0;
    for(i=1;i<=cntq;++i)
    {
        int l=qs[i].l;
        int r=qs[i].r;
        int t=qs[i].t;
        while(R<r)
            add(v[++R]);
        while(l<L)
            add(v[--L]);
        while(r<R)
            rem(v[R--]);
        while(L<l)
            rem(v[L++]);
        while(T<t)
        {
            ++T;
            if(L <= upds[T].p && upds[T].p <= R)
            {
                assert(v[upds[T].p] == upds[T].oldval);
                rem(v[upds[T].p]);
                add(upds[T].newval);
            }
            v[upds[T].p]=upds[T].newval;
        }
        while(t<T)
        {
            if(L <= upds[T].p && upds[T].p <= R)
            {
                assert(v[upds[T].p] == upds[T].newval);
                rem(v[upds[T].p]);
                add(upds[T].oldval);
            }
            v[upds[T].p]=upds[T].oldval;
            --T;
        }
        rz[qs[i].pz]=getans();
    }
    for(i=1;i<=cntq;++i)
        cout<<rz[i]<<'\n';
    return 0;
}