#include <bits/stdc++.h>

using namespace std;
int va[200005],vb[200005],viz[200005],cl[200005],ok=1;
vector<int>v[200005];
int dfs (int poz)
{
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(!viz[nn])
        {
            cl[nn]=3-cl[poz];
            dfs(nn);
        }
        else
            if(cl[nn]!=3-cl[poz])
                ok=0;
    }
}
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,a,b,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        vb[i]=b;
        va[i]=a;
    }
    for(i=1;i<=n;++i)
    {
        if(!viz[i])
        {
            cl[i]=1;
            dfs(i);
        }
    }
    if(ok==0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(i=1;i<=m;++i)
    {
        if(cl[vb[i]]==2)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}