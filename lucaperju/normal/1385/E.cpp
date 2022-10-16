#include <bits/stdc++.h>
using namespace std;
int viz[200005];
int instack[200005];
int ok=1;
vector <int> v[200005];
vector <int> x,y;
int tc;
int value[200005];
void dfs (int pz)
{
    instack[pz]=1;
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        int nn=v[pz][i];
        if(instack[nn])
            ok=0;
        if(!viz[nn])
            dfs(nn);
    }
    instack[pz]=0;
    value[pz]=++tc;
}
int main()
{
    long long n,m,i,j,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ok=1;
        for(i=1;i<=n;++i)
        {
            viz[i]=0;
            v[i].clear();
        }
        x.clear();
        y.clear();
        tc=0;
        for(i=1;i<=m;++i)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(a==0)
            {
                x.push_back(b);
                y.push_back(c);
            }
            else
            {
                v[b].push_back(c);
            }
        }
        for(i=1;i<=n;++i)
            if(!viz[i])
                dfs(i);
        if(ok)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
            continue;
        }
        for(i=0;i<x.size();++i)
        {
            int a=x[i];
            int b=y[i];
            if(value[a]>value[b])
                cout<<a<<' '<<b<<'\n';
            else
                cout<<b<<' '<<a<<'\n';
        }
        for(i=1;i<=n;++i)
        {
            for(j=0;j<v[i].size();++j) /// ffs
            {
                cout<<i<<' '<<v[i][j]<<'\n';
            }
        }
    }
    return 0;
}