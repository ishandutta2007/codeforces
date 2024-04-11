#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int f[200000];
int g[200000];
int h[200000];
int m=0;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		if(f[i]!=f[f[i]])
		{
			printf("-1");
			return 0;
		}
		else
		{
			if(g[f[i]]==0)
			{
				g[f[i]]=m+1;
				g[i]=m+1;
				h[m+1]=f[i];
				m++;
			}
			else g[i]=g[f[i]];
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=n;i++) printf("%d ",g[i]);
	printf("\n");
	for(int i=1;i<=m;i++) printf("%d ",h[i]);
	return 0;
}