#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
int n,m;
struct Edge
{
	int b,next;
}	edge[maxn];
int g[maxn],tot;
int ans[maxn];

void addedge(int a,int b)
{
	tot++;
	edge[tot].b=b;
	edge[tot].next=g[a];
	g[a]=tot;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		addedge(x,i);
	}
	int tmp=0;
	for (int i=1;i<=n;i++)
	{
		while (tmp>=0 && g[tmp]==0)	tmp-=3;
		if (g[tmp]!=0)
		{
			ans[i]=edge[g[tmp]].b;
			g[tmp]=edge[g[tmp]].next;
		}	else {printf("Impossible\n");return 0;}
		tmp++;
	}
	printf("Possible\n");
	for (int i=1;i<=n;i++)	printf("%d ",ans[i]);
	//system("pause");
	return 0;
}