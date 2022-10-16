#include <bits/stdc++.h>

using namespace std;
int v[1001][1001],l[1001][1001],r[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        if(n%2 == m%2)
        {
            cout<<"NO\n";
            continue;
        }
        l[1][1]=r[1][1]=v[1][1];
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(i==1 && j==1)
                    continue;
                else if(i==1)
                {
                    l[i][j]=r[i][j]=v[i][j]+l[i][j-1];
                }
                else if(j==1)
                {
                    l[i][j]=r[i][j]=v[i][j]+l[i-1][j];
                }
                else
                {
                    l[i][j]=v[i][j]+min(l[i-1][j],l[i][j-1]);
                    r[i][j]=v[i][j]+max(r[i-1][j],r[i][j-1]);
                }
            }
        }
        if(l[n][m]<=0 && r[n][m]>=0)
            cout<<"YES\n";
        else
            cout<<"No\n";
    }
    return 0;
}