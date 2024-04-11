#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int size[100005];
void dfs (int pz, int t)
{
    size[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
        size[pz]+=size[v[pz][i]];
    }
}
int getleaf (int pz, int t)
{
    if(v[pz].size()==1)
        return pz;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        return getleaf(v[pz][i],pz);
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        for(i=1;i<=n;++i)
            if(size[i]==n/2)
                break;
        if(i==n+1 || n%2)
        {
            cout<<1<<' '<<v[1][0]<<'\n'<<v[1][0]<<' '<<1<<'\n';
            continue;
        }
        int mx=v[i][0];
        for(j=0;j<v[i].size();++j)
            if(size[v[i][j]]>size[mx])
                mx=v[i][j];
        int a=getleaf(i,mx);
        cout<<a<<' '<<v[a][0]<<'\n'<<a<<' '<<mx<<'\n';
    }
    return 0;
}