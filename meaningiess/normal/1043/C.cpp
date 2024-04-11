#include<iostream>
#include<cstring>
using namespace std;
int f[1010][2],to[1010];char a[1010],b[1010];
void dfs(int x,int t)
{
	if (x==1) {cout<<f[x][t]<<' ';return;}
	dfs(x-1,to[x]);cout<<f[x][t]<<' ';
}
int main()
{
	int n,i;cin>>a+1;n=strlen(a+1);
	for (i=1;i<=n;i++)
	{
		if (a[i]=='a') f[i][0]=1,f[i][1]=0,to[i]=1;
		else f[i][0]=0,f[i][1]=1,to[i]=0;
	}
	dfs(n,0);
}