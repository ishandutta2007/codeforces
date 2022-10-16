#include <bits/stdc++.h>
using namespace std;
map<long long,vector<long long> >mp;
struct ura
{
    long long a,b,c;
} v[100005];
long long hsh(long long a, long long b)
{
    if(a>b)
        swap(a,b);
    return a*1000000LL+b;
}
vector <long long> edges[100005];
long long viz[100005],rzc[100005],kc;
void dfs (long long pz)
{
    viz[pz]=1;
    rzc[++kc]=pz;
    for(long long i=0; i<edges[pz].size(); ++i)
        if(!viz[edges[pz][i]])
            dfs(edges[pz][i]);
}
long long cate1(long long i)
{
    long long s=0;
    if(mp[hsh(v[i].a,v[i].b)].size()==1)
        ++s;
    if(mp[hsh(v[i].b,v[i].c)].size()==1)
        ++s;
    if(mp[hsh(v[i].a,v[i].c)].size()==1)
        ++s;
    return s;
}
long long scoate (long long i,long long j)
{
    if(mp[hsh(v[i].a,v[i].b)].size()==2 &&( mp[hsh(v[i].a,v[i].b)][0]==j || mp[hsh(v[i].a,v[i].b)][1]==j))
    mp[hsh(v[i].a,v[i].b)].pop_back();
    if(mp[hsh(v[i].c,v[i].b)].size()==2 &&( mp[hsh(v[i].c,v[i].b)][0]==j || mp[hsh(v[i].c,v[i].b)][1]==j))
    mp[hsh(v[i].b,v[i].c)].pop_back();
    if(mp[hsh(v[i].a,v[i].c)].size()==2 &&( mp[hsh(v[i].a,v[i].c)][0]==j || mp[hsh(v[i].a,v[i].c)][1]==j))
    mp[hsh(v[i].a,v[i].c)].pop_back();
}
void dfs1 (long long pz)
{
    viz[pz]=1;
    long long i=pz;
    rzc[++kc]=pz;
    long long h1=hsh(v[i].a,v[i].b);
    if(mp[h1].size()==2)
    {
        for(long long i=0;i<mp[h1].size();++i)
            if(mp[h1][i]!=pz)
            {
                scoate(mp[h1][i],pz);
                if(cate1(mp[h1][i])>=2 && !viz[mp[h1][i]])
                    dfs1(mp[h1][i]);
            }
    }
    h1=hsh(v[i].b,v[i].c);
    if(mp[h1].size()==2)
    {
        for(long long i=0;i<mp[h1].size();++i)
            if(mp[h1][i]!=pz)
            {
                scoate(mp[h1][i],pz);
                if(cate1(mp[h1][i])>=2 && !viz[mp[h1][i]])
                    dfs1(mp[h1][i]);
            }
    }
    h1=hsh(v[i].a,v[i].c);
    if(mp[h1].size()==2)
    {
        for(long long i=0;i<mp[h1].size();++i)
            if(mp[h1][i]!=pz)
            {
                scoate(mp[h1][i],pz);
                if(cate1(mp[h1][i])>=2 && !viz[mp[h1][i]])
                    dfs1(mp[h1][i]);
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,m,p,k,i,j,ok=0,t;
    long long a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            viz[i]=0;
        for(i=1; i<=n-2; ++i)
        {
            cin>>v[i].a>>v[i].b>>v[i].c;
            mp[hsh(v[i].a,v[i].b)].push_back(i);
            mp[hsh(v[i].b,v[i].c)].push_back(i);
            mp[hsh(v[i].a,v[i].c)].push_back(i);
        }
        for(i=1; i<=n-2; ++i)
        {
            long long h1=hsh(v[i].a,v[i].b);
            if(mp[h1].size()==1)
            {
                edges[v[i].a].push_back(v[i].b);
                edges[v[i].b].push_back(v[i].a);
            }
            h1=hsh(v[i].b,v[i].c);
            if(mp[h1].size()==1)
            {
                edges[v[i].c].push_back(v[i].b);
                edges[v[i].b].push_back(v[i].c);
            }
            h1=hsh(v[i].a,v[i].c);
            if(mp[h1].size()==1)
            {
                edges[v[i].a].push_back(v[i].c);
                edges[v[i].c].push_back(v[i].a);
            }
        }
        kc=0;;
        dfs(1);
        for(i=1; i<=n; ++i)
            cout<<rzc[i]<<' ';
        cout<<'\n';
        for(i=1; i<=n; ++i)
        {
            viz[i]=0;
        }
        kc=0;
        for(i=1; i<=n-2; ++i)
        {
            if(cate1(i)>=2 && !viz[i])
            {
                dfs1(i);
            }
        }
        for(i=1;i<=n-2;++i)
            cout<<rzc[i]<<' ';
        cout<<'\n';
        for(i=1;i<=n;++i)
        {
            while(edges[i].size())
                edges[i].pop_back();
            if(i>n-2)
                continue;
            long long h1=hsh(v[i].a,v[i].b);
            while(mp[h1].size())
                mp[h1].pop_back();
            h1=hsh(v[i].c,v[i].b);
            while(mp[h1].size())
                mp[h1].pop_back();
            h1=hsh(v[i].a,v[i].c);
            while(mp[h1].size())
                mp[h1].pop_back();
        }
    }
}