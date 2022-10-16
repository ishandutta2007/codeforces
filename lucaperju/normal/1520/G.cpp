#include <bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int w,n,m;
int v[2003][2003];
struct ura
{
    int i,j;
};
queue<ura>q;
long long dst[2003][2003];
void bfs (int a, int b)
{
    int i,j;
    q.push({a,b});
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            dst[i][j]=5000000;
    dst[a][b]=0;
    while(!q.empty())
    {
        ura x=q.front();
        q.pop();
        i=x.i;
        j=x.j;
        for(int d=0;d<=3;++d)
        {
            int ni=i+dx[d];
            int nj=j+dy[d];
            if(v[ni][nj]==-1)
                continue;
            if(dst[i][j]+1<dst[ni][nj])
            {
                dst[ni][nj]=1+dst[i][j];
                q.push({ni,nj});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j;
    cin>>n>>m>>w;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    bfs(1,1);
    long long rz;
    if(dst[n][m]!=5000000)
        rz=dst[n][m]*1LL*w;
    else
        rz=10000000000000000LL;
    long long mnc=rz;
    int ok=0;
    int ok1=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(v[i][j]>0 && dst[i][j]!=5000000)
            {
                mnc=min(mnc,dst[i][j]*1LL*w+v[i][j]);
                ok=1;
            }
        }
    long long mnc1=rz;
    bfs(n,m);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(v[i][j]>0 && dst[i][j]!=5000000)
            {
                ok1=1;
                mnc1=min(mnc1,dst[i][j]*1LL*w+v[i][j]);
            }
        }
    rz=min(rz,mnc+mnc1);
    if(dst[1][1]==5000000 && ok*ok1==0)
        cout<<-1;
    else
        cout<<rz;
}