#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=510;
int n,m,a,b,x,y,d[MAXN],G[MAXN][MAXN];
double p[MAXN],A[MAXN][MAXN],pi[MAXN],pj[MAXN],xx[MAXN];
inline int Hash(int i,int j){return (i-1)*n+j;}
void Gauss()
{
    for(int i=1;i<=n;i++)
    {
        int sub=0;
        for(int j=i;j<=n;j++) if(fabs(A[j][i])>fabs(A[sub][i])) sub=j;
        for(int j=1;j<=n+1;j++) swap(A[i][j],A[sub][j]);
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                double o=A[j][i]/A[i][i];
                for(int k=1;k<=n+1;k++) A[j][k]-=o*A[i][k];
            }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),G[x][y]++,G[y][x]++,d[x]++,d[y]++;
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    A[Hash(a,b)][n*n+1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            for(int ii=1;ii<=n;ii++) pi[ii]=G[i][ii]*(1-p[i])/d[i];
            pi[i]=p[i];
            for(int jj=1;jj<=n;jj++) pj[jj]=G[j][jj]*(1-p[j])/d[j];
            pj[j]=p[j];
            for(int ii=1;ii<=n;ii++)
                for(int jj=1;jj<=n;jj++)
                    A[Hash(ii,jj)][Hash(i,j)]+=pi[ii]*pj[jj];
        }
    n=n*n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            A[i][j]=-A[i][j];
    for(int i=1;i<=n;i++) A[i][i]+=1;
    Gauss();
    for(int i=n;i>=1;i--) xx[i]=A[i][n+1]/A[i][i];
    n=(int)(sqrt(n)+0.5);
    for(int i=1;i<n;i++) printf("%.06lf ",xx[Hash(i,i)]);
    printf("%.06lf\n",xx[Hash(n,n)]);
    return 0;
}