#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m,x,y,z;
LL f[100010][2][2][2],ans;
char str[100010];
bool calc(int a,int b,int c,int i,int j)
{
	a+=i-2,b+=i-1,c+=i-1;
	x=b,y=c,z=0;
	if(str[i]==j) x=max(x,a+1);
	y=max(y,x);
	if(str[i+1]==j) y=max(y,b+1);
	z=max(z,y);
	if(str[i+2]==j) z=max(z,c+1);
	x-=i-1,y-=i,z-=i;
	if(x>=0&&y>=0&&z>=0) return true;
	else return false;
}
int main()
{
	scanf("%d%d%s",&n,&m,str+1);
	for(int i=1;i<=n;i++) str[i]-='a';
	str[n+1]=26;
	for(int i=0;i<m;i++)
	{
		x=1;
		y=(i==str[1])?1:0;
		z=(i==str[1]||i==str[2])?1:0;
		f[1][x][y][z]++;
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(calc(0,0,0,i,j)) f[i+1][x][y][z]+=f[i][0][0][0];
			if(calc(0,0,1,i,j)) f[i+1][x][y][z]+=f[i][0][0][1];
			if(calc(0,1,0,i,j)) f[i+1][x][y][z]+=f[i][0][1][0];
			if(calc(0,1,1,i,j)) f[i+1][x][y][z]+=f[i][0][1][1];
			if(calc(1,0,0,i,j)) f[i+1][x][y][z]+=f[i][1][0][0];
			if(calc(1,0,1,i,j)) f[i+1][x][y][z]+=f[i][1][0][1];
			if(calc(1,1,0,i,j)) f[i+1][x][y][z]+=f[i][1][1][0];
			if(calc(1,1,1,i,j)) f[i+1][x][y][z]+=f[i][1][1][1];
		}
	ans=f[n][0][0][0]+f[n][1][0][0]+f[n][0][0][1]+f[n][1][0][1];
	printf("%I64d\n",ans);
	return 0;
}