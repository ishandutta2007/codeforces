#include<bits/stdc++.h>
using namespace std;
int a[5];
int u[4];
bool f[5],falg;
void dfs(int dep)
{
	if(dep==4)
	{
		if(u[1]+u[2]>u[3]&&u[1]+u[3]>u[2]&&u[2]+u[3]>u[1])
		{
			printf("TRIANGLE");
			exit(0);
		}
		if(u[1]+u[2]>=u[3]&&u[1]+u[3]>=u[2]&&u[2]+u[3]>=u[1])falg=true;
		return;
	}
	for(int i=1;i<=4;i++)
	if(f[i]==false)
	{
		f[i]=true;
		u[dep]=a[i];
		dep++;
		dfs(dep);
		dep--;
		u[dep]=0;
		f[i]=false;
	}
}
int main()
{
	scanf("%d%d%d%d",a+1,a+2,a+3,a+4);
	dfs(1);
	if(falg==true)printf("SEGMENT");
	else printf("IMPOSSIBLE");
return 0;
}