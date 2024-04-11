#include <bits/stdc++.h>
using namespace std;
int v[103][103];
void perm (int i, int j, int m)
{
    int k;
    int aux=v[i][m];
    for(k=m;k>=j;--k)
    {
        v[i][k]=v[i][k-1];
    }
    v[i][j]=aux;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,i,m,j,k,cnt,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        for(i=1;i<=n;++i)
        {
            sort(v[i]+1,v[i]+m+1);
        }
        for(j=1;j<=m;++j)
        {
            int mn=v[1][j];
            for(i=1;i<=n;++i)
                mn=min(mn,v[i][j]);
            for(i=1;i<=n;++i)
            {
                if(v[i][j]==mn)
                {
                    mn=-1;
                    continue;
                }
                perm(i,j,m);
            }
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}