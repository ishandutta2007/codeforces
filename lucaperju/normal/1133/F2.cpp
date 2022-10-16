#include <bits/stdc++.h>

using namespace std;
vector <int> v[200005];
int viz[200005],vall,t[200005],ok[200005];
bool ok1[200005],viz1[200005];
int tata (int val)
{
    if(t[val]==0 || t[val]==val)
        return val;
    t[val]=tata(t[val]);
    return t[val];
}
void dfs (int poz)
{
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(viz[nn]==0)
        {
            dfs(nn);
        }
        else
        if(viz[nn]==2)
            t[tata(vall)]=tata(nn);
    }
}
void dfs1 (int poz)
{
    viz1[poz]=1;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(!viz1[nn])
        {
            cout<<poz<<' '<<nn<<'\n';
            dfs1(nn);
        }
    }
}
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,x,y,k,cnt=0,cnt1=0;
    long long mx=0;
    char c;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pz=1;
    viz[pz]=1;
    for(i=0;i<v[pz].size();++i)
    {
        viz[v[pz][i]]=2;
    }
    for(i=0;i<v[pz].size();++i)
    {
        vall=v[pz][i];
        dfs(v[pz][i]);
    }
    for(i=0;i<v[pz].size();++i)
    {
        ok[tata(v[pz][i])]++;
        if(ok[tata(v[pz][i])]==1)
            ++cnt;
    }
    if(cnt<=k && k<=v[pz].size())
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO";
        return 0;
    }
    for(i=0;i<v[pz].size();++i)
    {
        ok[tata(v[pz][i])]=0;
    }
    viz1[pz]=1;
    for(i=0;i<v[pz].size();++i)
    {
        if(ok[tata(v[pz][i])]==0)
        {
            cout<<pz<<' '<<v[pz][i]<<'\n';
            ok[tata(v[pz][i])]=1;
            ok1[v[pz][i]]=1;
            --k;
            viz1[v[pz][i]]=1;
        }
    }
    for(i=0;i<v[pz].size();++i)
    {
        if(!ok1[v[pz][i]] && k)
        {
            cout<<pz<<' '<<v[pz][i]<<'\n';
            ok1[v[pz][i]]=1;
            --k;
            viz1[v[pz][i]]=1;
        }
    }
    for(i=0;i<v[pz].size();++i)
    {
        if(ok1[v[pz][i]])
            dfs1(v[pz][i]);
    }
    return 0;
}