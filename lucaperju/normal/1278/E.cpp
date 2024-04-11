#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int rz[1000006],viz[1000006],k=0;
vector<int> v[500005];
int dfs (int poz)
{
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
        if(!viz[v[poz][i]])
            rz[++k]=v[poz][i];
    rz[++k]=poz;
    for(int i=(int)v[poz].size()-1;i>=0;--i)
        if(!viz[v[poz][i]])
            dfs(v[poz][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,i,j,s=0,t;
        cin>>n;
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        rz[++k]=1;
        dfs(1);
        for(i=1;i<=2*n;++i)
            v[rz[i]].push_back(i);
        for(i=1;i<=n;++i)
        {
            cout<<v[i][(int)v[i].size()-2]<<' '<<v[i][(int)v[i].size()-1]<<'\n';
        }
    return 0;
}