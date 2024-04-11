#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
struct UFS
{
	int fa[MAXN];
	void reset(int n)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
	}
	int find(int x)
	{
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int i,int j)
	{
		fa[find(i)]=find(j);
	}
}UFS1,UFS2;
int n,Q,type,x,y;
int main()
{
	scanf("%d%d",&n,&Q);
	UFS1.reset(n);
	UFS2.reset(n);
	while(Q--)
	{
		scanf("%d%d%d",&type,&x,&y);
		if(type==1) UFS1.uni(x,y);
		else if(type==2)
		{
			int p=y;
			while(true)
			{
				int t=p;
				if(UFS2.find(p)<=x) break;
				p=UFS2.find(p)-1;
				UFS1.uni(t,p);
				UFS2.uni(t,p);
			}
		}
		else
		{
			if(UFS1.find(x)==UFS1.find(y)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}