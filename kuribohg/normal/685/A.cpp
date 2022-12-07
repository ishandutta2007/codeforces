#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans,nn,mm,a,b,c[10];
bool used[7];
void dfs(int x,int k)
{
	used[x]=true;
	c[k]=x;
	if(k==a+b)
	{
		int xx=0,yy=0;
		for(int i=1;i<=a;i++)
			xx=xx*7+c[i];
		for(int i=a+1;i<=a+b;i++)
			yy=yy*7+c[i];
		if(xx<n&&yy<m) ans++;
		used[x]=false;
		return;
	}
	for(int i=0;i<7;i++)
		if(!used[i]) dfs(i,k+1);
	used[x]=false;
}
int main()
{
	scanf("%d%d",&n,&m),nn=n-1,mm=m-1;
	while(nn) nn/=7,a++;
	while(mm) mm/=7,b++;
	if(a==0) a++;
	if(b==0) b++;
	if(a+b>7) {puts("0");return 0;}
	for(int i=0;i<7;i++)
		dfs(i,1);
	printf("%d\n",ans);
	return 0;
}