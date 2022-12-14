#include<iostream>
#include<cstdio>
using namespace std;
int n,q,tp,x,y;
struct dsu
{
	int pa[222222];
	void Init()
	{
		for (int i=1;i<=n;i++) pa[i]=i;
	}
	int root(int x)
	{
		if (pa[x]!=x) pa[x]=root(pa[x]);
		return pa[x]; 
	}
	void Union(int x,int y)
	{
		int rx=root(x),ry=root(y);
		if (rx==ry) return;
		pa[rx]=ry;
	}
}d1,d2;
int main()
{
	scanf("%d%d",&n,&q);
	d1.Init();d2.Init();
	while(q--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1)
		{
			d1.Union(x,y);
		}
		else if (tp==2)
		{
			for (int i=x;i<y;i=d2.root(i))
			{
				if (d2.root(i)>=y) break;
				d2.Union(i,d2.root(i)+1); 
				d1.Union(i,d2.root(i));
			}
		}
		else 
		{
			if (d1.root(x)==d1.root(y)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}