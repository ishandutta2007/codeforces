#include <iostream>
#include <vector>
using namespace std;
int pz[6][1003],viz[1003],tp[1003],x,d[1003];
bool mat[1003][1003];
vector <int> v[1003];
void dfs (int poz)
{
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
        if(!viz[v[poz][i]])
            dfs(v[poz][i]);
    tp[++x]=poz;
}
int main()
{
    int n,m,i,j,mx=0;
    cin>>n>>m;
    for(j=1;j<=m;++j)
    {
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            pz[j][a]=i;
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            int ok=1;
            for(int k=1;k<=m;++k)
            {
                if(pz[k][j]<=pz[k][i])
                    ok=0;
            }
            if(ok)
            {
                v[i].push_back(j);
                mat[i][j]=1;
            }
        }
    for(i=1;i<=n;++i)
        if(!viz[i])
            dfs(i);
    for(i=n;i>=1;--i)
    {
        d[i]=1;
        for(j=i+1;j<=n;++j)
            if(mat[tp[j]][tp[i]])
                d[i]=max(d[i],1+d[j]);
        mx=max(mx,d[i]);
    }
    cout<<mx;
    return 0;
}