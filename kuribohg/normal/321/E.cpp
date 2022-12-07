#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int getint()
{
	int con=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') con=con*10+c-'0',c=getchar();
	return con;
}
const int INF=2000000000;
int n,k,s[4010][4010],f[810][4010];
inline int w(int l,int r)
{
	return s[r][r]-s[l-1][r]-s[r][l-1]+s[l-1][l-1];
}
void solve(int f[],int g[],int l,int r,int L,int R)
{
	if(l>r) return;
	int mid=(l+r)>>1,pos=L;
	for(int i=L;i<=min(R,mid-1);i++)
	{
		int res=g[i]+w(i+1,mid);
		if(res<f[mid]) f[mid]=res,pos=i;
	}
	solve(f,g,l,mid-1,L,pos);
	solve(f,g,mid+1,r,pos,R);
}
int main()
{
	n=getint(),k=getint();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=getint();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]+=s[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]+=s[i-1][j];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++) f[1][i]=w(1,i);
	for(int i=2;i<=k;i++) solve(f[i],f[i-1],i,n,i-1,n-1);
	printf("%d\n",f[k][n]/2);
	return 0;
}