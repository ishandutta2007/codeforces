#include <bits/stdc++.h>

using namespace std;
int v[1003][1003];
int ocp[1003][1003];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs (int i, int j)
{
    v[i][j]=0;
    for(int x=0;x<=3;++x)
    {
        int ni=i+dx[x];
        int nj=j+dy[x];
        if(v[ni][nj]==1)
            dfs(ni,nj);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            if(c=='#')
                v[i][j]=1;
            else
                v[i][j]=0;
        }
    }
    for(i=1;i<=n;++i)
    {
        int cnt=0;
        for(j=1;j<=m;++j)
            if(v[i][j]==1 && v[i][j-1]==0)
                ++cnt;
        if(cnt>1)
        {
            cout<<-1;
            return 0;
        }
    }
    for(j=1;j<=m;++j)
    {
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i][j]==1 && v[i-1][j]==0)
                ++cnt;
        if(cnt>1)
        {
            cout<<-1;
            return 0;
        }
    }
    for(i=1;i<=n;++i)
    {
        int cnt=0;
        for(j=1;j<=m;++j)
            if(v[i][j]==1 && v[i][j-1]==0)
                ++cnt;
        if(cnt==1)
            for(j=1;j<=m;++j)
                ocp[i][j]=1;
    }
    for(j=1;j<=m;++j)
    {
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i][j]==1 && v[i-1][j]==0)
                ++cnt;
        if(cnt==1)
            for(i=1;i<=n;++i)
                ocp[i][j]=1;
    }
    for(i=1;i<=n;++i)
    {
        int cnt=0;
        for(j=1;j<=m;++j)
            if(v[i][j]==1 || ocp[i][j]==0)
                ++cnt;
        if(cnt==0)
        {
            cout<<-1;
            return 0;
        }
    }
    for(j=1;j<=m;++j)
    {
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i][j]==1 || ocp[i][j]==0)
                ++cnt;
        if(cnt==0)
        {
            cout<<-1;
            return 0;
        }
    }
    int cnt=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(v[i][j]==1)
            {
                dfs(i,j);
                ++cnt;
            }
        }
    cout<<cnt;
    return 0;
}