#include <bits/stdc++.h>
using namespace std;

int matchl[200005];
int matchr[200005];
struct ura
{
    int a,id;
};
vector<ura>v[200005];
vector<int>vr[200005];
bool vis[200005];
bool visr[200005];
bool dfs (int pz)
{
    if(vis[pz])
        return 0;
    vis[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(matchr[v[pz][i].a]==-1 || dfs(matchr[v[pz][i].a]))
        {
            matchl[pz]=v[pz][i].a;
            matchr[v[pz][i].a]=pz;
            return 1;
        }
    }
    return 0;
}
void dfsr (int pz);
void dfsl (int pz)
{
    vis[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(visr[v[pz][i].a] || v[pz][i].a==matchl[pz])
            continue;
        dfsr(v[pz][i].a);
    }
}
void dfsr (int pz)
{
    visr[pz]=1;
    for(int i=0;i<vr[pz].size();++i)
    {
        if(vis[vr[pz][i]])
            continue;
        dfsl(vr[pz][i]);
    }
}
struct ura1
{
    int nod,ed;
};
vector<ura1>vc;
int findedge (int a, int b)
{
    for(int i=0;i<v[a].size();++i)
    {
        if(v[a][i].a==b)
            return v[a][i].id;
    }
}
int main()
{
    int i,j,m,k=0,q,n1,n2;
    cin>>n1>>n2>>m>>q;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back({b,i});
    }
    for(i=1;i<=n1;++i)
        matchl[i]=-1;
    for(i=1;i<=n2;++i)
        matchr[i]=-1;
    while(1)
    {
        for(i=1;i<=n1;++i)
            vis[i]=0;
        bool ok=0;
        for(i=1;i<=n1;++i)
            if(matchl[i]==-1)
                ok|=dfs(i);
        if(!ok)
            break;
    }
    for(i=1;i<=n1;++i)
        vis[i]=0;
    for(i=1;i<=n1;++i)
    {
        if(matchl[i]!=-1)
            vr[matchl[i]].push_back(i);
    }
    for(i=1;i<=n1;++i)
        if(matchl[i]==-1)
            dfsl(i);
    for(i=1;i<=n1;++i)
    {
        if(!vis[i])
        {
            vc.push_back({i,findedge(i,matchl[i])});
        }
    }
    for(i=1;i<=n2;++i)
    {
        if(visr[i])
        {
            vc.push_back({-i,findedge(matchr[i],i)});
        }
    }
    long long s=0;
    for(i=0;i<vc.size();++i)
        s+=vc[i].ed;
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            cout<<"1\n";
            cout<<vc.back().nod<<'\n';
            s-=vc.back().ed;
            vc.pop_back();
            cout<<s<<'\n';
            cout.flush();
        }
        else if(a==2)
        {
            cout<<vc.size()<<'\n';
            for(int i=0;i<vc.size();++i)
                cout<<vc[i].ed<<' ';
            cout<<'\n';
            cout.flush();
        }
    }
    return 0;
}