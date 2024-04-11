#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
int perm[30][5];
int n,fv[11],vv[11],x;
void bck (int poz)
{
    if(poz>4)
    {
        ++x;
        for(int i=1;i<=4;++i)
            perm[x][i]=vv[i];
        return;
    }
    for(int i=1;i<=4;++i)
        if(!fv[i])
        {
            fv[i]=1;
            vv[poz]=i;
            bck(poz+1);
            fv[i]=0;
        }
}
char msk[10];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,s=0,cnt0,n,a,k,ok=0,m,mn=30000003,cnt1,cnt;
    cin>>n>>m;
    char v[n+3][m+3],bst[n+3][m+3],cur[n+3][m+3];
    for(i=1;i<=n;++i)
        cin>>(v[i]+1); // A G C T
    bck(1);
    msk[1]='A';
    msk[2]='G';
    msk[3]='C';
    msk[4]='T';
    for(int y=1;y<=24;++y)
    {
        cnt=0;
        for(i=0;i<n;i+=2)
        {
            cur[i+1][1]=msk[perm[y][1]];
            cur[i+1][2]=msk[perm[y][2]];
            cur[i+2][1]=msk[perm[y][3]];
            cur[i+2][2]=msk[perm[y][4]];
            if(cur[i+1][1]!=v[i+1][1])
                ++cnt;
            if(cur[i+1][2]!=v[i+1][2])
                ++cnt;
            if(cur[i+2][1]!=v[i+2][1])
                ++cnt;
            if(cur[i+2][2]!=v[i+2][2])
                ++cnt;
        }
        for(j=3;j<=m;++j)
        {
            cnt0=cnt1=0;
            if(j%2)
            {
                for(i=1;i<=n;++i)
                {
                    if(i%2)
                    {
                        cnt0+=(cur[1][1]!=v[i][j]);
                        cnt1+=(cur[2][1]!=v[i][j]);
                    }
                    else
                    {
                        cnt1+=(cur[1][1]!=v[i][j]);
                        cnt0+=(cur[2][1]!=v[i][j]);
                    }
                }
            }
            else
            {
                for(i=1;i<=n;++i)
                {
                    if(i%2)
                    {
                        cnt0+=(cur[1][2]!=v[i][j]);
                        cnt1+=(cur[2][2]!=v[i][j]);
                    }
                    else
                    {
                        cnt1+=(cur[1][2]!=v[i][j]);
                        cnt0+=(cur[2][2]!=v[i][j]);
                    }
                }
            }
            cnt+=min(cnt0,cnt1);
            if(cnt0<cnt1)
                for(i=1;i<=n;++i)
                    cur[i][j]=cur[(i-1)%2+1][(j-1)%2+1];
            else
                for(i=1;i<=n;++i)
                    cur[i][j]=cur[3-((i-1)%2+1)][(j-1)%2+1];
        }
        if(cnt<mn)
        {
            for(i=1;i<=n;++i)
                for(j=1;j<=m;++j)
                    bst[i][j]=cur[i][j];
            mn=cnt;
        }
        /// -----------------------------------------------------------------------------
        cnt=0;
        for(j=0;j<m;j+=2)
        {
            cur[1][j+1]=msk[perm[y][1]];
            cur[1][j+2]=msk[perm[y][2]];
            cur[2][j+1]=msk[perm[y][3]];
            cur[2][j+2]=msk[perm[y][4]];
            if(cur[1][1+j]!=v[1][1+j])
                ++cnt;
            if(cur[1][2+j]!=v[1][2+j])
                ++cnt;
            if(cur[2][1+j]!=v[2][1+j])
                ++cnt;
            if(cur[2][2+j]!=v[2][2+j])
                ++cnt;
        }
        for(i=3;i<=n;++i)
        {
            cnt0=cnt1=0;
            if(i%2)
            {
                for(j=1;j<=m;++j)
                {
                    if(j%2)
                    {
                        cnt0+=(cur[1][1]!=v[i][j]);
                        cnt1+=(cur[1][2]!=v[i][j]);
                    }
                    else
                    {
                        cnt1+=(cur[1][1]!=v[i][j]);
                        cnt0+=(cur[1][2]!=v[i][j]);
                    }
                }
            }
            else
            {
                for(j=1;j<=m;++j)
                {
                    if(j%2)
                    {
                        cnt0+=(cur[2][1]!=v[i][j]);
                        cnt1+=(cur[2][2]!=v[i][j]);
                    }
                    else
                    {
                        cnt1+=(cur[2][1]!=v[i][j]);
                        cnt0+=(cur[2][2]!=v[i][j]);
                    }
                }
            }
            cnt+=min(cnt0,cnt1);
            if(cnt0<cnt1)
                for(j=1;j<=m;++j)
                    cur[i][j]=cur[(i-1)%2+1][(j-1)%2+1];
            else
                for(j=1;j<=m;++j)
                    cur[i][j]=cur[(i-1)%2+1][3-((j-1)%2+1)];
        }
        if(cnt<mn)
        {
            for(i=1;i<=n;++i)
                for(j=1;j<=m;++j)
                    bst[i][j]=cur[i][j];
            mn=cnt;
        }
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
            cout<<bst[i][j];
        cout<<'\n';
    }
}