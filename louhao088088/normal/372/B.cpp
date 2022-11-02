// Problem: CF372B Counting Rectangles is Fun
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF372B
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2021-12-03 21:05:20
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=55,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,q,ans[45][45][45][45],sum[45][45],b[45][45],g[45][45][45][45],x,y,lx,rx;
char a[maxn][maxn];
bool check(int x,int y,int lx,int ly)
{
	return (sum[lx][ly]-sum[x-1][ly]-sum[lx][y-1]+sum[x-1][y-1])==0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();q=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++)
		{
			b[i][j]=a[i][j]-'0';
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+b[i][j];
			//cout<<sum[i][j]<<" ";
		}//cout<<endl;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=i;k++)
				for(int l=1;l<=j;l++)
					g[i][j][k][l]=g[i][j][k-1][l]+g[i][j][k][l-1]-g[i][j][k-1][l-1]+check(k,l,i,j);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=i;k++)
				for(int l=1;l<=j;l++)
				{
					ans[k][l][i][j]=ans[k][l][i-1][j]+ans[k][l][i][j-1]-ans[k][l][i-1][j-1]
					+g[i][j][i][j]-g[i][j][k-1][j]-g[i][j][i][l-1]+g[i][j][k-1][l-1];
				
				}
		}
	for(int i=1;i<=q;i++)
	{
		x=read(),y=read(),lx=read(),rx=read();
		printf("%d\n",ans[x][y][lx][rx]);
	}
 	return 0;
}