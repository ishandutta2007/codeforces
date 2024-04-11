#include <bits/stdc++.h>
 
using namespace std;
vector <int> v[200005];
vector <int> v1[200005];
int ocp[200005][2];
int rz[200005];
int viz[200005];
int inqueue[200005];
void dfs0 (int pz)
{
    ocp[pz][0]=1;
    for(int i=0;i<v[pz].size();++i)
        if(!ocp[v[pz][i]][0])
            dfs0(v[pz][i]);
}
void dfs1 (int pz)
{
    ocp[pz][1]=1;
    for(int i=0;i<v1[pz].size();++i)
        if(!ocp[v1[pz][i]][1])
            dfs1(v1[pz][i]);
}
bool dfs (int pz)
{
    viz[pz]=1;
    inqueue[pz]=1;
    int ok=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(inqueue[v[pz][i]])
            ok=1;
        if(!viz[v[pz][i]])
            if(dfs(v[pz][i]))
                ok=1;
    }
    inqueue[pz]=0;
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a,cnt=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v1[b].push_back(a);
    }
    int ok=0;
    for(i=1;i<=n;++i)
        if(viz[i]==0 && v1[i].size()==0)
            if(dfs(i))
                ok=1;
    for(i=1;i<=n;++i)
        if(!viz[i])
            ok=1;
    if(ok)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        if(ocp[i][0]+ocp[i][1]==0)
        {
            rz[i]=1;
            ++cnt;
        }
        else
            rz[i]=0;
        if(!ocp[i][0])
            dfs0(i);
        if(!ocp[i][1])
            dfs1(i);
    }
    cout<<cnt<<'\n';
    for(i=1;i<=n;++i)
    {
        if(rz[i]==1)
            cout<<'A';
        else
            cout<<'E';
    }
    return 0;
}