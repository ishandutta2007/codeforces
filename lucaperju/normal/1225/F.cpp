#include <bits/stdc++.h>
using namespace std;
int depth[200005],t[200005];
int lant[200005];
int fiu[200005];
vector<int>v[200005];
vector<int>rz;
void dfs1 (int pz)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(lant[v[pz][i]])
            fiu[pz]=v[pz][i];
    }
    for(int i=0;i<v[pz].size();++i)
    {
        if(!lant[v[pz][i]])
        {
            rz.push_back(fiu[pz]);
            lant[v[pz][i]]=1;
            fiu[v[pz][i]]=fiu[pz];
            fiu[pz]=v[pz][i];
        }
    }
    if(fiu[pz])
        dfs1(fiu[pz]);
}
int main()
{
    long long n,m,i,j,x,y,k,l,r;
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>t[i];
        v[t[i]].push_back(i);
    }
    depth[0]=1;
    int mx=0;
    for(i=1;i<n;++i)
    {
        depth[i]=1+depth[t[i]];
        if(depth[i]>depth[mx])
            mx=i;
    }
    int pz=mx;
    while(1)
    {
        lant[pz]=1;
        if(pz==0)
            break;
        pz=t[pz];
    }
    dfs1(0);
    pz=0;
    for(i=1;i<=n;++i)
    {
        cout<<pz<<' ';
        pz=fiu[pz];
    }
    cout<<'\n';
    cout<<rz.size()<<'\n';
    for(i=int(rz.size()-1);i>=0;--i)
        cout<<rz[i]<<' ';
    return 0;
}