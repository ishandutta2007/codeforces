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
struct DSU
{
    vector<int> t;
    DSU(int n) : t(n, -1) {}
    bool sameSet (int a, int b) { return root(a)==root(b);}
    int root (int a) { return t[a] < 0 ? a : t[a] = root(t[a]);}
    bool join (int a, int b) {
        a = root(a); b = root(b);
        if(a == b) return false;
        t[a] = b; return true;
    }
};
int dst[2][300005];
int ts[300005];
int cnt[300005];
vector<int>v[300005];
void dfsdst (int pz, int t, int a)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dst[a][v[pz][i]]=1+dst[a][pz];
        dfsdst(v[pz][i],pz,a);
    }
}
void dfst (int pz, int t)
{
    ts[pz]=t;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfst(v[pz][i],pz);
    }
}
vector<int>vc;
vector<vector<int> >rzs;
int dfscount (int pz, int t)
{
    int cntc=0;
    int cat=0;
    int need=cnt[pz]%2;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        cntc+=dfscount(v[pz][i],pz);
        if(cnt[v[pz][i]]%2)
            ++cat;
    }
    if(need)
    {
        if(cat)
        {
            --cat;
            cntc-=cat/2;
            return cntc;
        }
        else
            return cntc+1;
    }
    else
    {
        return cntc-cat/2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>n>>m;
    DSU dsu(n+1);
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        if(!dsu.sameSet(a,b))
        {
            v[a].push_back(b);
            v[b].push_back(a);
            dsu.join(a,b);
        }
    }
    dfst(1,-1);
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        dst[0][a]=0;
        dfsdst(a,-1,0);
        dst[1][b]=0;
        dfsdst(b,-1,1);
        vc.resize(dst[0][b]+1);
        for(i=1;i<=n;++i)
            if(dst[0][i]+dst[1][i]==dst[0][b])
                vc[dst[0][i]]=i;
        for(i=0;i<vc.size()-1;++i)
        {
            a=vc[i];
            b=vc[i+1];
            if(ts[a]==b)
                ++cnt[a];
            if(ts[b]==a)
                ++cnt[b];
        }
        rzs.push_back(vc);
    }
    int cntt=0;
    for(i=1;i<=n;++i)
        if(cnt[i]%2)
            ++cntt;
    if(cntt==0)
    {
        cout<<"YES\n";
        for(i=0;i<rzs.size();++i)
        {
            cout<<rzs[i].size()<<'\n';
            for(j=0;j<rzs[i].size();++j)
                cout<<rzs[i][j]<<' ';
            cout<<'\n';
        }
        return 0;
    }
    cout<<"NO\n";
    cout<<dfscount(1,-1);
    return 0;
}