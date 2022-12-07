#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,p[110],s;
double f[2][1010*1010],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),s+=p[i];
    if(m==1) {printf("%.015lf\n",1.0);return 0;}
    f[0][0]=m-1;
    for(int i=0;i<n;i++)
    {
        int pre=i&1,cur=pre^1;
        for(int j=0;j<=m*n;j++) f[cur][j]=0;
        for(int j=0;j<=m*n;j++)
        {
            if(j+1<=m*n) f[cur][j+1]+=f[pre][j]/(m-1);
            if(j+p[i+1]<=m*n) f[cur][j+p[i+1]]-=f[pre][j]/(m-1);
            if(j+p[i+1]+1<=m*n) f[cur][j+p[i+1]+1]+=f[pre][j]/(m-1);
            if(j+m+1<=m*n) f[cur][j+m+1]-=f[pre][j]/(m-1);
        }
        for(int j=1;j<=m*n;j++)
            f[cur][j]+=f[cur][j-1];
    }
    for(int i=0;i<s;i++)
        ans+=f[n&1][i];
    printf("%.015lf\n",ans+1);
    return 0;
}