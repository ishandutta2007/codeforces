#include <iostream>
#include <vector>
using namespace std;
vector <int> v1[6005];
vector <int> v2[6005];
int n,pz,m,viz[6005],q[6005],st,dr,cnt=0,pzst;
void citire()
{
    int a,b,i;
    cin>>n>>m>>pz;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
}
void dfs1 (int poz)
{
    viz[poz]=2;
    for(int i=0;i<v1[poz].size();++i)
        if(!viz[v1[poz][i]])
            dfs1(v1[poz][i]);
}
void dfs2 (int poz)
{
    viz[poz]=1;
    pzst=poz;
    if(!v2[poz].size())
        q[++dr]=poz;
    for(int i=0;i<v2[poz].size();++i)
        if(!viz[v2[poz][i]])
            dfs2(v2[poz][i]);
}
void bfs (int poz)
{
    int nc,nn,i;
    cnt+=max(1,dr-st+1);
    if(dr-st+1==0)
        q[++dr]=poz;
    while(st<=dr)
    {
        nc=q[st];
        viz[nc]=2;
        for(i=0;i<v1[nc].size();++i)
        {
            nn=v1[nc][i];
            if(viz[nn]!=2)
                q[++dr]=nn,viz[nn]=2;
        }
        ++st;
    }
}
int main()
{
    citire();
    dfs1(pz);
    for(int i=1;i<=n;++i)
    {
        if(!viz[i])
        {
            st=1;
            dr=0;
            dfs2(i);
            bfs(pzst);
        }
    }
    cout<<cnt;
    return 0;
}