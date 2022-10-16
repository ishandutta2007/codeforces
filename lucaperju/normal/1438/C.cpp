#include <bits/stdc++.h>
using namespace std;
int v[103][103];
int ok[103][103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,i,m,j,mx=0,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                if(v[i][j]%2!=(i+j)%2)
                    ++v[i][j];
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