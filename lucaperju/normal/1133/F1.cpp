#include <bits/stdc++.h>

using namespace std;
vector <int> v[200005];
int viz[200005];
void dfs (int poz)
{
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(!viz[nn])
        {
            cout<<poz<<' '<<nn<<'\n';
            dfs(nn);
        }
    }
}
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,x,y,k,cnt=0,cnt1=0;
    long long mx=0;
    char c;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
    {
        if(v[i].size()>mx)
        {
            mx=v[i].size();
            pz=i;
        }
    }
    viz[pz]=1;
    for(i=0;i<v[pz].size();++i)
    {
        viz[v[pz][i]]=1;
        cout<<pz<<' '<<v[pz][i]<<'\n';
    }
    for(i=0;i<v[pz].size();++i)
    {
        dfs(v[pz][i]);
    }
    return 0;
}