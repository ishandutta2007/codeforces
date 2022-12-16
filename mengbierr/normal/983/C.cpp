#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,a[2010],b[2010],x[10],f[2010][10][800],p,m[800],u[800][10],v[800],w[10000],c[800][10],d[800][10],ans=1e9;
inline void dfs(int i,int l)
{
    int j,k=0;
    if(i==l)
    {
    p++;
    m[p]=i-1;
    for(j=1,k=0;j<i;j++)
      u[p][j]=x[j],k=k*10+x[j];
    v[p]=k;
    w[k]=p;
      return;
    }
    for(j=x[i-1];j<=9;j++)
      {
       x[i]=j;
       dfs(i+1,l);
      }
}
inline int del(int i,int j)
{
    int k,l;
    for(k=1,l=0;k<=m[i];k++)
      if(u[i][k]!=j)
        l=l*10+u[i][k];
    return w[l];
}
inline int add(int i,int j)
{
    if(m[i]==4)
      return 0;
    int k,l;
    for(k=1,l=0;k<=m[i] && u[i][k]<j;k++)
      l=l*10+u[i][k];
    l=l*10+j;
    for(;k<=m[i];k++)
      l=l*10+u[i][k];
    return w[l];
}
inline void minn(int &a,int b)
{
    a=min(a,b);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	x[0]=1;
	for(i=1;i<=5;i++)
	  dfs(1,i);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i],&b[i]);
	for(i=1;i<=p;i++)
	  for(j=1;j<=9;j++)
	    {
         c[i][j]=add(i,j);
         d[i][j]=del(i,j);
        }
    for(i=1;i<=n+1;i++)
      for(j=1;j<=9;j++)
        for(k=1;k<=p;k++)
          f[i][j][k]=1e9;
    f[1][1][1]=0;
    for(i=1;i<=n+1;i++)
      for(k=p;k>0;k--)
        for(j=1;j<=9;j++)
          {
           for(l=1;l<=m[k];l++)
             minn(f[i][u[k][l]][d[k][u[k][l]]],f[i][j][k]+abs(j-u[k][l]));
           if(m[k]<4 && i<=n)
             minn(f[i+1][a[i]][c[k][b[i]]],f[i][j][k]+abs(j-a[i]));
           if(i==n+1 && k==1)
             minn(ans,f[i][j][k]);
          }
    printf("%d\n",ans+2*n);
	return 0;
}