#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int n,m,a[1010][1010],maxnum,d[120000],p[1010][1010];
bool nprime[120000];
int nowp,line[1010],row[1010],ans=2e9;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            maxnum=max(maxnum,a[i][j]);
        }
    for(int i=2;i*i<=maxnum+10000;i++)
        if(!nprime[i])
        {
            for(int j=i+i;j<=maxnum+10000;j+=i)
                nprime[j]=true;
        }
    d[1]=1;
    nowp=1;
    for(int i=2;i<=maxnum+10000;i++)
        if(!nprime[i])
        {
            for(int j=nowp+1;j<=i;j++)
                d[j]=i-j;
            nowp=i;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            p[i][j]=d[a[i][j]];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            line[i]+=p[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            row[i]+=p[j][i];
    for(int i=1;i<=n;i++) ans=min(ans,line[i]);
    for(int i=1;i<=m;i++) ans=min(ans,row[i]);
    printf("%d\n",ans);
    return 0;
}