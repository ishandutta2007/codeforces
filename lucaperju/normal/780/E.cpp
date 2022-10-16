#include <bits/stdc++.h>
using namespace std;
vector <int> v[200005];
int drum [400005],viz[200005],x;
void dfs (int pz)
{
    drum[++x]=pz;
    ++viz[pz];
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            dfs(v[pz][i]);
            drum[++x]=pz;
            ++viz[pz];
        }
    }
}
int main ()
{
    int n,i,s=0,m,k;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    while(viz[drum[x]]>1)
        --viz[drum[x]],--x;
    i=1;
    while(viz[drum[i]]>1)
        --viz[drum[i]],++i;
    int cn=i;
    n=n*2;
    if(n%k)
        n+=k;
    int cat=(x-i)/(n/k)+1,ram=x-cn+1;
    for(i=1;i<=cat;++i)
    {
        cout<<min(n/k,ram)<<' ';
        for(int j=cn;j<=min(cn+n/k-1,x);++j)
            cout<<drum[j]<<' ';
        cn+=min(n/k,ram);
        ram-=(n/k);
        cout<<'\n';
    }
    for(;i<=k;++i)
        cout<<1<<' '<<1<<'\n';
}