#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=510;
int n,a[MAXN],ans[MAXN];
char p[MAXN][MAXN];
bool bigger()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<ans[i]) return true;
		if(a[i]>ans[i]) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%s",p[i]+1);
	for(int i=1;i<=n;i++) ans[i]=a[i];
	for(int i=1;i<=n;i++) p[i][i]='1';
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(p[i][k]=='1'&&p[k][j]=='1') p[i][j]='1';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(p[i][j]=='1')
			{
				swap(a[i],a[j]);
				if(bigger())
					for(int i=1;i<=n;i++) ans[i]=a[i];
				else swap(a[i],a[j]);
			}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}