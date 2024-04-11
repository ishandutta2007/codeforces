#include <bits/stdc++.h>
using namespace std;
int fel[200005];
vector <int> v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            fel[i]=0;
        }
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
        }
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(fel[i]==2)
                ++cnt;
            if(fel[i]==0)
                for(j=0;j<v[i].size();++j)
                    fel[v[i][j]]=max(fel[v[i][j]],1);
            else if(fel[i]==1)
                for(j=0;j<v[i].size();++j)
                    fel[v[i][j]]=2;
        }
        cout<<cnt<<'\n';
        for(i=1;i<=n;++i)
        {
            if(fel[i]==2)
                cout<<i<<' ';
        }
        cout<<'\n';
    }
    return 0;
}