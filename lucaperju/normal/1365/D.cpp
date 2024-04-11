#include <bits/stdc++.h>

using namespace std;
int v[103][103];
int v1[103][103];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int a, int b)
{
    v1[a][b]=2;
    for(int i=0;i<=3;++i)
    {
        int na=a+dx[i];
        int nb=b+dy[i];
        if(v1[na][nb]==1)
            dfs(na,nb);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            if(c=='.')
                v[i][j]=0;
            else if(c=='#')
                v[i][j]=1;
            else if(c=='G')
                v[i][j]=2;
            else
                v[i][j]=3;
        }
        for(i=0;i<=n+1;++i)
            for(j=0;j<=m+1;++j)
                v1[i][j]=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                v1[i][j]=1;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                if(v[i][j]==1)
                    v1[i][j]=0;
                if(v[i][j]==3)
                    v1[i-1][j]=v1[i+1][j]=v1[i][j-1]=v1[i][j+1]=0;
            }
        if(v1[n][m]==1)
        dfs(n,m);
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                if(v[i][j]==2 && v1[i][j]!=2)
                {
                    i=n+2;
                    break;
                }
            }
        if(i==n+1)
            cout<<"YEs\n";
        else
            cout<<"no\n";
    }
    return 0;
}