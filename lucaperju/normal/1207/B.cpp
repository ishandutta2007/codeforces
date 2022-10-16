#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int ok[55][55];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,j,cnt=0,m,p,h,c,a,b;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    for(i=1;i<n;++i)
        for(j=1;j<m;++j)
            if(v[i][j]==1 && v[i+1][j]==1 && v[i][j+1]==1 && v[i+1][j+1]==1)
                ok[i][j]=ok[i+1][j]=ok[i][j+1]=ok[i+1][j+1]=1,++cnt;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v[i][j]==1 && ok[i][j]==0)
            {
                cout<<-1;
                return 0;
            }
    cout<<cnt<<'\n';
    for(i=1;i<n;++i)
        for(j=1;j<m;++j)
            if(v[i][j]==1 && v[i+1][j]==1 && v[i][j+1]==1 && v[i+1][j+1]==1)
                cout<<i<<' '<<j<<'\n';
    return 0;
}