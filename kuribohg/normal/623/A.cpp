#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,m,a[510][510],d[510],ans[510];
bool check()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int x=0;
			if(abs(ans[j]-ans[i])<=1) x=1;
			else x=0;
			if(a[i][j]!=x) return false;
		}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1,d[x]++,d[y]++;
	for(int i=1;i<=n;i++) if(d[i]==n-1) ans[i]=2;
	for(int i=1;i<=n;i++)
		if(!ans[i])
		{
			ans[i]=1;
			for(int j=1;j<=n;j++)
				if(a[i][j]==0&&!ans[j]) ans[j]=3;
				else if(!ans[j]) ans[j]=1;
		}
	bool ok=check();
	if(!ok) puts("No");
	else
	{
		puts("Yes");
		for(int i=1;i<=n;i++)
			putchar('a'-1+ans[i]);
		puts("");
	}
	return 0;
}